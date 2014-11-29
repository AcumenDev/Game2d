#include <UpdateEventDto.hpp>
#include "SceneManager.hpp"
SceneManager::SceneManager(std::shared_ptr<Logger> log, SDL_Renderer* renderer, std::shared_ptr<NotificationServices> notificationServices) {
    _log = log;
    _renderer = renderer;
    _notificationServices = notificationServices;
}

SceneManager::~SceneManager() {
}

std::shared_ptr<SceneNode> SceneManager::AddChildNode(std::string name) {
    auto childNode = std::make_shared<SceneNode>(_log, name);
    _childNodes.push_back(childNode);
    return childNode;
}

void SceneManager::Draw() {
    for(const auto & node : _childNodes) {
        node->Draw();
    }

    if(_sceneManagerFpsCounterBase!=nullptr) {
        _sceneManagerFpsCounterBase->Update(_fps_current);
    }
    _calcFps();
    SDL_RenderPresent( _renderer );
}

void SceneManager::_calcFps() {
    _fps_frames++;
    if (_fps_lasttime < SDL_GetTicks() - 1000) {
        _fps_lasttime = SDL_GetTicks();
        _fps_current = _fps_frames;
        _fps_frames = 0;
    }
}


void SceneManager::Update(float delta, std::shared_ptr<EventInputSystem> eventInputSystem) {
    for(const auto & node : _childNodes) {
        node->Update(UpdateEventDto(delta, _notificationServices, eventInputSystem));
    }
}
void SceneManager::SetFpsListener(std::shared_ptr<SceneManagerFpsCounterBase> sceneManagerFpsCounterBase) {
    _sceneManagerFpsCounterBase = sceneManagerFpsCounterBase;
}

