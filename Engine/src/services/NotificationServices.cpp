#include "services/NotificationServices.hpp"


void NotificationServices::Notify(const std::string& event, const int &data) const {
    for (const auto& listener : _listeners.at(event)) {
        listener(data);
    }
}

void NotificationServices::RegisterListener(const std::string& event, std::function<void(const int& )> listener ) {
    _listeners[event].push_back(listener);
}

