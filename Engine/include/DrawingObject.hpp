#ifndef DRAWINGOBJECT_H
#define DRAWINGOBJECT_H
#include <memory>
#include "EventInputSystem.hpp"
#include "Texture.hpp"
#include "Logger.hpp"
class DrawingObject {
public:
    DrawingObject(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, IPoint iPoint);
    virtual ~DrawingObject() {};
    virtual void Draw();
    virtual void Update(float delta,std::shared_ptr<EventInputSystem> eventInputSystem) = 0;
protected:
    std::shared_ptr<Texture> _texture;
    IPoint _iPoint;
    std::shared_ptr<Logger> _log;
};
#endif // DRAWINGOBJECT_H
