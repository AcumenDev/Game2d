#ifndef GAMEOBJECTBASE_H
#define GAMEOBJECTBASE_H
#include <memory>
#include <UpdateEventDto.hpp>
#include "ObjectsDrawing/ObjectDrawingBase.hpp"

using namespace Graphic;
using std::shared_ptr;

class GameObjectBase {

public:
    virtual void Update(UpdateEventDto updateEventDto) = 0;
    virtual shared_ptr<ObjectDrawingBase> GetDrawing() const = 0;
};

#endif