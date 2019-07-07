//
// Created by vinokurov on 29.06.2019.
//

#include <functional>
#include <string>
#include "TcpSocket.h"
#include "Sockets.h"
#include "../Logger.h"
#include "../modules/json/single_include/nlohmann/json.hpp"
#include "IConnectionClosedListener.h"
#include "IDataArrivedListener.h"

#define BUFFER_SIZE     10240

using namespace std::string_literals;

TcpSocket::TcpSocket(int socketDescriptor) :
    _socketDescriptor{ socketDescriptor },
    _run{ true },
    _readThread{ std::bind(&TcpSocket::readDataProc, this) },
    _connectionClosedListener{ nullptr },
    _dataArrivedListener{ nullptr }
{
    _readThread.detach();
}

void TcpSocket::close() {
    if (_run.load()) {
        Logger::getInstace().log("Closing socket...");
        _run = false;
        shutdown(_socketDescriptor, 0);
#ifdef _WIN32
        closesocket(_socketDescriptor);
#endif

#ifdef __linux__

#endif
        if (_readThread.joinable()) {
            Logger::getInstace().log("Join to reading thread");
            _readThread.join();
        } else {
            Logger::getInstace().log("Reading thread isn't joinable");
        }
        Logger::getInstace().log("Socket is closed");
    }
}

void TcpSocket::readDataProc() {
    if (_socketDescriptor < 0 || _socketDescriptor == INVALID_SOCKET) {
        Logger::getInstace().log("Invalid socket descriptor!");
        return;
    }
    Logger::getInstace().log("Start read thread...");

    char buffer[BUFFER_SIZE];
    size_t storedSize = 0 , bytesAvailable;
    while (_run.load()) {
        try {
            bytesAvailable = BUFFER_SIZE - storedSize;
            Logger::getInstace().log("Waiting for socket data... Bytes available: "s + std::to_string(bytesAvailable));
            auto len = recv(_socketDescriptor, buffer + storedSize, bytesAvailable, 0);
            if (len <= 0) {
                Logger::getInstace().log("Connection closed!");
                if (_connectionClosedListener != nullptr) {
                    _connectionClosedListener->onConnectionClosed(this);
                }
                break;
            }
            Logger::getInstace().log("Bytes received: "s + std::to_string(len));
            auto start = std::chrono::steady_clock::now();
            if (_dataArrivedListener != nullptr) {
                size_t size = len;
                char *buffer_ptr = buffer;
                if (prepareRawData(&buffer_ptr, &size)) {
                    if (size > 0) {
                        buffer[size] = 0;
                        try {
                            nlohmann::json jsonData = nlohmann::json::parse(buffer_ptr);
                            _dataArrivedListener->onDataArrived(this, jsonData);
                        } catch (nlohmann::json::parse_error &ex) {
                            Logger::getInstace().log("Json parsing error: "s + ex.what());
                        }
                    }
                    storedSize = 0;
                } else {
                    Logger::getInstace().log("Package marked as incomplete!");
                    storedSize = len;
                }
            } else {
                Logger::getInstace().log("Data arrival listener not set!");
            }
            auto end = std::chrono::steady_clock::now();
            Logger::getInstace().log("Package process time: "s + std::to_string(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) + " mcsec");
        } catch (std::exception &ex) {
            Logger::getInstace().log("Socket read data exception: "s + ex.what());
        }
    }
    close();
    Logger::getInstace().log("Read thread terminated");
}

bool TcpSocket::prepareRawData(char **buffer, size_t *size) {
    return true;
}

TcpSocket::~TcpSocket() {
    close();
}

void TcpSocket::setConnectionClosedListener(IConnectionClosedListener *listener) {
    _connectionClosedListener = listener;
}

void TcpSocket::setDataArrivedListener(IDataArrivedListener *listener) {
    _dataArrivedListener = listener;
}

void TcpSocket::writeRawData(const char *data, size_t size) {
    send(_socketDescriptor, data, size, 0);
}

void TcpSocket::write(const nlohmann::json &json) {
    writeRawData(json.dump());
}

void TcpSocket::writeRawData(std::string_view str) {
    writeRawData(str.data(), str.size());
}

void TcpSocket::write(const ::Package &package)
{
    nlohmann::json json;
    package.toJson(json);
    write(json);
}
