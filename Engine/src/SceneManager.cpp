#include "SceneManager.hpp"
SceneManager::SceneManager() {
}

SceneManager::~SceneManager() {
}

std::shared_ptr<SceneNode> SceneManager::AddChildNode(std::string name) {
    auto childNode = std::make_shared<SceneNode>(name);
    _childNodes.push_back(childNode);
    return childNode;
}

void SceneManager::Draw() {
    for(const auto & node : _childNodes) {
        node->Draw();
    }
}
