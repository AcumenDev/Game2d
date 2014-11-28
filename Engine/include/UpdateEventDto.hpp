#ifndef UPDATEEVENTDTO_H
#define UPDATEEVENTDTO_H
#include "memory"
#include "EventInputSystem.hpp"
#include "services/NotificationServices.hpp"

class UpdateEventDto {
public:
    float delta;
    std::shared_ptr<EventInputSystem> eventInputSystem;
    std::shared_ptr<NotificationServices> notificationServices;
};
#endif