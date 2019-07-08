//
// Created by kir on 07.07.19.
//

#include "../Logger.h"
#include "EventProvider.h"


EventProvider::EventProvider()
{

}

EventProvider::~EventProvider()
{
    std::for_each(_processorList.begin(), _processorList.end(),
            [](EventProcessor *processor) {
                delete processor;
            });
}

EventProvider &EventProvider::getInstance()
{
    static EventProvider inst;
    return inst;
}

const EventProcessor *EventProvider::getEventProcessor(int eventTypeId)
{
    auto it = std::find_if(_processorList.begin(), _processorList.end(),
            [eventTypeId](const EventProcessor *processor) {
                return processor->isEventSupported(eventTypeId);
            });
    return it == _processorList.end() ? nullptr : *it;
}

#include "events/GameStartEvent.h"
#include "events/UserChangeNameEvent.h"

void EventProvider::load()
{
    Logger::getInstace().log("Start event processors initialization...");

    registerEventProcessor(new GameStartEvent());
    registerEventProcessor(new UserChangeNameEvent());

    Logger::getInstace().log("Event processors initialization complete.");
}

void EventProvider::registerEventProcessor(EventProcessor *processor)
{
    _processorList.push_back(processor);
}