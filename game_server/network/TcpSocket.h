//
// Created by vinokurov on 29.06.2019.
//

#ifndef GAME_SERVER_TCPSOCKET_H
#define GAME_SERVER_TCPSOCKET_H

#include <inttypes.h>
#include <thread>
#include <atomic>
#include <queue>
#include <mutex>
#include <condition_variable>
#include "../modules/json/single_include/nlohmann/json.hpp"


class IConnectionClosedListener;

class IDataArrivedListener;

class TcpSocket
{
public:
    using Package = std::pair<const char *, size_t>;

    explicit TcpSocket(int socketDescriptor);

    virtual ~TcpSocket();

    void close();

    virtual void write(const nlohmann::json &json);

    void setConnectionClosedListener(IConnectionClosedListener *listener);

    void setDataArrivedListener(IDataArrivedListener *listener);

protected:
    virtual bool prepareRawData(char **buffer, size_t *size);

    virtual void writeRawData(const char *data, size_t size);

    virtual void writeRawData(std::string_view str);

private:
    void readDataProc();

    int _socketDescriptor;

    std::thread _readThread;
    std::atomic_bool _run;

    IConnectionClosedListener *_connectionClosedListener;
    IDataArrivedListener * _dataArrivedListener;
};


#endif //GAME_SERVER_TCPSOCKET_H
