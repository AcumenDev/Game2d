#ifndef DRAWINGOBJECT_H
#define DRAWINGOBJECT_H
#include <memory>
#include "EventInputSystem.hpp"
class DrawingObject {
public:
    DrawingObject();
    virtual ~DrawingObject();
    virtual void Draw() = 0;
    virtual void Update(float delta,std::shared_ptr<EventInputSystem> eventInputSystem) = 0;
protected:
private:
};
#endif // DRAWINGOBJECT_H
