#include "SceneNode.hpp"
#include <algorithm>
SceneNode::SceneNode(std::shared_ptr<Logger> log, std::string nameNode){
    _log = log;
    _nameNode  = nameNode;
}

SceneNode::~SceneNode() {
}

void SceneNode::Draw() {
    for(const auto & drawingObject : _drawingObjects) {
        drawingObject->Draw();
    }
    for(const auto & node : _childNodes) {
        node->Draw();
    }
}
void SceneNode::Update(UpdateEventDto updateEventDto) {
    for(const auto & drawingObject : _drawingObjects) {
        drawingObject->Update(updateEventDto);
    }

    for(const auto & node : _childNodes) {
        node->Update( updateEventDto);
    }

    if(_drawingObjects.size()>0) {
        _drawingObjects.erase(
                std::remove_if(_drawingObjects.begin(), _drawingObjects.end(), [this](std::shared_ptr<DrawingObject> item)-> bool {
            if (!item->IsLive()) {
                _log->Debug("SceneNode", "Deleted drawing object: from node" + _nameNode);
              return true;
            }
            return false;
        }),_drawingObjects.end()
        );
    }
}

void SceneNode::AttachObject(std::shared_ptr<DrawingObject> drawingObject) {
    _drawingObjects.push_back(drawingObject);
}
