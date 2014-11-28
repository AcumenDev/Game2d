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
void SceneNode::Update(float delta,std::shared_ptr<EventInputSystem> eventInputSystem, std::shared_ptr<NotificationServices> notificationServices) {
    for(const auto & drawingObject : _drawingObjects) {
        drawingObject->Update( delta, eventInputSystem, notificationServices);
    }
    for(const auto & node : _childNodes) {
        node->Update( delta, eventInputSystem, notificationServices);
    }
}

void SceneNode::AttachObject(std::shared_ptr<DrawingObject> drawingObject) {
    _drawingObjects.push_back(drawingObject);
}
