#ifndef DRAWINGOBJECT_H
#define DRAWINGOBJECT_H
#include <memory>
#include <services/NotificationServices.hpp>
#include "EventInputSystem.hpp"
#include "Texture.hpp"

#include "utils/logger/Logger.hpp"
#include "UpdateEventDto.hpp"
#include "ObjectBase.hpp"
#include "Utils/Point.hpp"

using namespace Utils;

class DrawingObject {
public:
    DrawingObject(std::shared_ptr<Texture> texture, FPoint Point);
    virtual ~DrawingObject() {
    };
    virtual void Draw();
    virtual void Update(UpdateEventDto updateEventDto) = 0;
    virtual bool IsLive();
protected:
    std::shared_ptr<Texture> _texture;
    FPoint _point;
    bool _isLive;
};
#endif // DRAWINGOBJECT_H
