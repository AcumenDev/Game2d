#ifndef NOTIFICATIONSERVICES_H
#define NOTIFICATIONSERVICES_H

#include <map>
#include <vector>
#include <functional>
#include <iostream>
#include <exception>

class NotificationServices {
public:
    NotificationServices() {
    };

    virtual ~NotificationServices() {
    };

    void RegisterListener(const std::string &event, std::function<void(const int& )> listener );

    void Notify(const std::string &event, const int &data) const;

    NotificationServices(const NotificationServices &) = delete;

    NotificationServices &operator=(const NotificationServices &) = delete;

private:
    std::map<std::string, std::vector<std::function<void(const int& )>>> _listeners;
};

#endif // NOTIFICATIONSERVICES_H
