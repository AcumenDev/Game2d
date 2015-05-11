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
    long _objectId;
public:
    GameObjectBase() : _objectId(-1) { }

    long getObjectId() const {
        return _objectId;
    }

    GameObjectBase *setObjectId(long objectId) {
        _objectId = objectId;
        return this;
    }

    virtual void Update(UpdateEventDto updateEventDto) = 0;

    virtual shared_ptr<ObjectDrawingBase> GetDrawing() const = 0;

    virtual void SetSceneNone(shared_ptr<SceneNode> sceneNode) { };
};

#endif