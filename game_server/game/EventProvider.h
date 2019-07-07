//
// Created by kir on 07.07.19.
//

#ifndef GAME_SERVER_EVENTPROVIDER_H
#define GAME_SERVER_EVENTPROVIDER_H

#include "events/EventProcessor.h"

class EventProvider
{
public:
    static EventProvider &getInstance();

    const EventProcessor *getEventProcessor(int eventTypeId);

    void load();

    void registerEventProcessor(EventProcessor *processor);

private:
    EventProvider();
    ~EventProvider();
    EventProvider(EventProvider &) = delete;
    EventProvider(EventProvider &&) = delete;
    EventProvider& operator =(EventProvider &) = delete;
    EventProvider& operator =(EventProvider &&) = delete;

    std::vector<EventProcessor *> _processorList;
};


#endif //GAME_SERVER_EVENTPROVIDER_H
