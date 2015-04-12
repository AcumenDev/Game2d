#ifndef GAMEOBJECTBASE_H
#define GAMEOBJECTBASE_H
#include <memory>
#include "UpdateEventDto.hpp"
#include "SceneNode.hpp"
#include "ObjectsDrawing/ObjectDrawingBase.hpp"

using namespace Graphic;
using std::shared_ptr;
class SceneNode;

class GameObjectBase {

public:
    virtual void Update(UpdateEventDto updateEventDto) = 0;
    virtual shared_ptr<ObjectDrawingBase> GetDrawing() const = 0;
    virtual void SetSceneNone(shared_ptr<SceneNode> sceneNode) {};
};

#endif