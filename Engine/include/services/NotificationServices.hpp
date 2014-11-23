#ifndef NOTIFICATIONSERVICES_H
#define NOTIFICATIONSERVICES_H
#include <map>
#include <vector>
#include <functional>
#include <iostream>
template <typename EventType>
class NotificationServices {
public:
    /** Default constructor */
    NotificationServices();
    /** Default destructor */
    virtual ~NotificationServices();
    // disallow copying and assigning
    NotificationServices(const NotificationServices&)=delete;
    NotificationServices& operator=(const NotificationServices&)=delete;
    template <typename Listener>
    void RegisterListener(const EventType& event, Listener&& listener);
    void Notify(const EventType& event, const void* data) const;
private:
    std::map<EventType, std::vector<std::function<void(const void *)>>> _listeners;
};

#endif // NOTIFICATIONSERVICES_H
