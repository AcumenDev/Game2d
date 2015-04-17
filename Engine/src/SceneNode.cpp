#include "SceneNode.hpp"
#include <algorithm>

SceneNode::SceneNode(string nameNode, bool fixedCord) {
    _nameNode = nameNode;
    _fixedCord = fixedCord;
    _thisSceneNode.reset(this);
}

SceneNode::~SceneNode() {
    _childNodes.clear();
    _drawingObjectsOld.clear();
    _gameObjects.clear();
    _drawingObjects.clear();
    _thisSceneNode.reset();
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

    for (const auto &drawingObject : _drawingObjectsOld) {
        drawingObject->Update(updateEventDto);
    }

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
}

void SceneNode::AttachObject(shared_ptr<DrawingObject> drawingObject) {
    _drawingObjectsOld.push_back(drawingObject);
}

void SceneNode::AttachObject(shared_ptr<ObjectDrawingBase> drawingObject) {
    _drawingObjects.push_back(drawingObject);
}

void SceneNode::AttachObject(shared_ptr<GameObjectBase> gameObjectBase) {
    _gameObjects.push_back(gameObjectBase);

    gameObjectBase->SetSceneNone(_thisSceneNode);
}
