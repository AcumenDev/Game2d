#include "services/NotificationServices.hpp"

template <typename EventType >
void NotificationServices<EventType>::Notify(const EventType& event, const void* data) const {
    for (const auto& listener : _listeners.at(event)) {
        listener(data);
    }
}

template <typename EventType>
template <typename Listener>
void NotificationServices<EventType>::RegisterListener(const EventType& event, Listener&& listener) {
    _listeners[event].push_back(std::forward<Listener>(listener));
}

