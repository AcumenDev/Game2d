#include "SceneNode.hpp"

SceneNode::SceneNode(std::string name) {
    _name  = name;
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
}

void SceneNode::AttachObject(std::shared_ptr<DrawingObject> drawingObject) {
    _drawingObjects.push_back(drawingObject);
}
