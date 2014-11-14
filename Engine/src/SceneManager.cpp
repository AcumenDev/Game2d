#include "SceneManager.hpp"
SceneManager::SceneManager(std::shared_ptr<Logger> log, SDL_Renderer* renderer) {
    _log = log;
    _renderer = renderer;
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
    SDL_RenderPresent( _renderer );
}

void SceneManager::Update(float delta, std::shared_ptr<EventInputSystem> eventInputSystem) {
    for(const auto & node : _childNodes) {
        node->Update(delta, eventInputSystem);
    }

}
