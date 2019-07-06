//
// Created by vinokurov on 29.06.2019.
//

#include <cstring>
#include <iostream>
#include "WebSocket.h"
#include "../Logger.h"
#include "../core/string_functions.h"
#include "../modules/cppcodec/cppcodec/base64_rfc4648.hpp"
#include "../modules/digestpp/digestpp.hpp"

using  namespace std::string_literals;

#define SECURITY_KEY_SIZE       20
#define BUFFER_SIZE             10240

WebSocket::WebSocket(int socketDescriptor) :
    TcpSocket(socketDescriptor),
    _state{ ChannelState::Open },
    _webSocketSessionInitListener{ nullptr }
{

}

WebSocket::~WebSocket() {

}

bool WebSocket::prepareRawData(char **buffer, size_t *size) {
    if (_state == ChannelState::Ready) {
        uint8_t b1 = **buffer;
        uint8_t b2 = (*buffer)[1];
        bool isFinal = b1 & 0x80;
        auto opcode = b1 & 0x0F;
        bool mask = b2 & 0x80;
        bool small_pkg = (b2 & 0x7F) <= 125;
        uint16_t length = 0;
        if (small_pkg) {
            length = b2 & 0x7F;
        } else {
            memcpy(&length, *buffer + 2, 2);
        }
        Logger::getInstace().log("Package received: FIN="s + std::to_string(isFinal) + " OPCODE=" + std::to_string(opcode) + " MASK="s + std::to_string(mask) + " LEN=" + std::to_string(length));

        if (mask) {
            uint8_t masking_key[4];
            memcpy(masking_key, *buffer + (small_pkg ? 2 : 4), 4);

            Logger::getInstace().log("Decompiling data...");
            auto start = std::chrono::steady_clock::now();
            for (uint16_t idx = 0; idx < length; ++idx) {
                (*buffer)[idx] = (*buffer)[idx + 6] ^ masking_key[idx % 4];
            }
            Logger::getInstace().log("Data ready. Process time: "s + std::to_string(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start).count()) + " mcsec");
            *size = length;
        } else {
            *buffer += 2;
        }
    } else {
        if (strstr(*buffer, "\r\n\r\n") == nullptr) {
            return false;
        }

        auto securityKeyIdx = strstr(*buffer, "Sec-WebSocket-Key:");
        std::string basedAnswerKey;
        if (securityKeyIdx != nullptr) {
            securityKeyIdx += 18;
            basedAnswerKey = std::string(securityKeyIdx, strstr(securityKeyIdx, "\r\n") - securityKeyIdx);
            trim(basedAnswerKey);
        }
        basedAnswerKey += "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
        unsigned char hashBuffer[SECURITY_KEY_SIZE];
        memset(hashBuffer, 0, SECURITY_KEY_SIZE);
        digestpp::sha1().absorb(basedAnswerKey).digest(hashBuffer, SECURITY_KEY_SIZE);
        basedAnswerKey = cppcodec::base64_rfc4648::encode(hashBuffer, SECURITY_KEY_SIZE);

        *size = 0;
        auto msg = "HTTP/1.1 101 Web Socket Protocol Handshake\r\n"
                   "Upgrade: WebSocket\r\n"
                   "Connection: Upgrade\r\n"s +
                   "Sec-WebSocket-Accept:" + basedAnswerKey + "\r\n" +
                   "WebSocket-Origin: http://localhost:11555\r\n"
                   "WebSocket-Location: ws://localhost:11555/demo\r\n\r\n";
        writeRawData(msg.c_str(), msg.size());
        _state = ChannelState::Ready;
        if (_webSocketSessionInitListener != nullptr) {
            _webSocketSessionInitListener->onSessionInit(this);
        }
    }
    return true;
}

void WebSocket::writeRawData(const char *data, size_t size) {
    TcpSocket::writeRawData(data, size);
}

void WebSocket::writeRawData(std::string_view str) {
    Logger::getInstace().log("Add websocket control bytes");
    char data[BUFFER_SIZE];
    memset(data, 0, BUFFER_SIZE);
    data[0] = 0x81;
    uint16_t message_size = str.size();
    uint8_t startIdx = 2;
    if (message_size <= 125) {
        data[1] = message_size;
    } else {
        startIdx = 4;
        data[1] = 0x7E;
        data[3] = message_size & 0xFF; // собираем длину сообщения
        data[2] = (message_size >> 8) & 0xFF; // собираем длину сообщения
    }
    str.copy(data + startIdx, message_size);
    auto len = message_size + startIdx;
    TcpSocket::writeRawData(data, len);
}

void WebSocket::setOnWebSocketSessionInitListener(IWebSocketSessionInitListener *listener) {
    _webSocketSessionInitListener = listener;
}