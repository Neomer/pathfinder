//
// Created by vinokurov on 29.06.2019.
//

#include <cstring>
#include "WebSocket.h"
#include "../core/string_functions.h"
#include "../modules/cppcodec/cppcodec/base64_rfc4648.hpp"
#include "../modules/digestpp/digestpp.hpp"

using  namespace std::string_literals;

#define SECURITY_KEY_SIZE       20

WebSocket::WebSocket(int socketDescriptor) :
    TcpSocket(socketDescriptor),
    _state{ ChannelState::Open }
{

}

WebSocket::~WebSocket() {

}

bool WebSocket::prepareRawData(char **buffer, size_t *size) {
    if (_state == ChannelState::Ready) {

    } else {
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
    }
    return true;
}

void WebSocket::writeRawData(const char *data, size_t size) {
    TcpSocket::writeRawData(data, size);
}
