//
// Created by kir on 26.06.19.
//

#include <iostream>
#include <functional>
#include <iomanip>
#include "Logger.h"

Logger::Logger() :
    _run{ true },
    _writeThread{ std::bind(&Logger::writeProc, this) }
{
    _writeThread.detach();
}

Logger::~Logger()
{
    _run = false;
    if (_writeThread.joinable()) {
        _writeThread.join();
    }
}

Logger &Logger::getInstace()
{
    static Logger instance;
    return instance;
}

void Logger::log(std::thread::id threadId, std::string_view text)
{
    std::lock_guard lock(_queueMutex);
    _messageQueue.push(Msg{ threadId, std::string{text} });
}

void Logger::log(std::string_view text)
{
    log(std::this_thread::get_id(), text);
}


void Logger::writeProc()
{
    while (_run.load()) {
        if (!_messageQueue.empty()) {
            std::lock_guard guard(_queueMutex);
            _messageCopyQueue.swap(_messageQueue);
        }
        while (!_messageCopyQueue.empty()) {
            auto msg = _messageCopyQueue.front();
            std::cout << '[' << std::hex << std::setw(4) << msg.ThreadId << "] " << msg.Text << std::endl;
            _messageCopyQueue.pop();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
