#ifndef UPDATEEVENTDTO_H
#define UPDATEEVENTDTO_H
#include "memory"
#include "EventInputSystem.hpp"
#include "services/NotificationServices.hpp"

class UpdateEventDto {
public:
    UpdateEventDto(
            float delta,
            std::shared_ptr<NotificationServices> notificationServices,
            std::shared_ptr<EventInputSystem> eventInputSystem)
            : delta(delta),
              notificationServices(notificationServices),
              eventInputSystem(eventInputSystem) {
    }
    float delta;
    std::shared_ptr<EventInputSystem> eventInputSystem;
    std::shared_ptr<NotificationServices> notificationServices;
};
#endif