#ifndef BACKGROUNDOBJECT_HPP
#define BACKGROUNDOBJECT_HPP
#include "DrawingObject.hpp"
#include "Texture.hpp"
#include "Utils/IPoint.hpp"
#include "Logger.hpp"
class BackgroundObject : public DrawingObject {
public:
    BackgroundObject(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, IPoint iPoint);
    virtual ~BackgroundObject();
    void Draw() override;
    void Update(float delta,std::shared_ptr<EventInputSystem> eventInputSystem, std::shared_ptr<NotificationServices> notificationServices) override;
};

#endif // BACKGROUNDOBJECT_HPP
