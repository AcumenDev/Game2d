#include "SceneNode.hpp"
#include <algorithm>

SceneNode::SceneNode(string nameNode, bool fixedCord) {
    _nameNode = nameNode;
    _fixedCord = fixedCord;
    Logger::Get()->Debug("SceneNode", "Create node: " + _nameNode);
}

SceneNode::~SceneNode() {
    Logger::Get()->Debug("SceneNode", "Delete node: " + _nameNode);
    _drawingObjectsOld.clear();
    _gameObjects.clear();
    _drawingObjects.clear();
    _childNodes.clear();
}

void SceneNode::Draw() {
    if (_fixedCord) {
        Render::Get()->RenderTolocal();
    } else {
        Render::Get()->RenderToGlobal();
    }
    for (const auto &drawingObject : _drawingObjectsOld) {
        drawingObject->Draw();
    }

    for (const auto &gameObject : _gameObjects) {
        auto draw = gameObject->GetDrawing();
        if (draw) {
            draw->Draw();
        }
    }
    for (const auto &drawingObject : _drawingObjects) {
        drawingObject->Draw();
    }

    for (const auto &node : _childNodes) {
        node->Draw();
    }
}

void SceneNode::Update(UpdateEventDto updateEventDto) {


    for (const auto &gameObject : _gameObjects) {
        gameObject->Update(updateEventDto);
    }


    for (const auto &node : _childNodes) {
        node->Update(updateEventDto);
    }

    if (_drawingObjectsOld.size() > 0) {
        _drawingObjectsOld.erase(
                std::remove_if(_drawingObjectsOld.begin(), _drawingObjectsOld.end(),
                               [this](std::shared_ptr<DrawingObject> item) -> bool {
                                   if (!item->IsLive()) {
                                       Logger::Get()->Debug("SceneNode",
                                                            "Deleted drawing object: from node" + _nameNode);
                                       return true;
                                   }
                                   return false;
                               }), _drawingObjectsOld.end()
        );
    }

    for (const auto &drawingObject : _drawingObjectsOld) {
        drawingObject->Update(updateEventDto);
    }
}

void SceneNode::AttachObject(shared_ptr<DrawingObject> drawingObject) {
    _drawingObjectsOld.push_back(drawingObject);
}

void SceneNode::AttachObject(shared_ptr<ObjectDrawingBase> drawingObject) {
    _drawingObjects.push_back(drawingObject);
}

void SceneNode::AttachObject(shared_ptr<GameObjectBase> gameObjectBase) {
    _gameObjects.push_back(gameObjectBase);

    gameObjectBase->SetSceneNone(shared_from_this());
}

bool SceneNode::DeleteObjectForId(unsigned int objectId) {

    bool status = false;
    _gameObjects.erase(
            std::remove_if(_gameObjects.begin(), _gameObjects.end(),
                           [this, objectId, &status](std::shared_ptr<GameObjectBase> item) -> bool {
                               if (item->getObjectId() == objectId) {
                                   Logger::Get()->Debug("SceneNode",
                                                        "Deleted game object: " + std::to_string(objectId) +
                                                        " from node: " + _nameNode);
                                   status = true;
                                   return true;
                               }
                               return false;
                           }), _gameObjects.end()
    );

    if (status) {
        return true;
    }

    for (const auto &node : _childNodes) {
        if (node->DeleteObjectForId(objectId)) {
            return true;
        }
    }
    return false;
}
