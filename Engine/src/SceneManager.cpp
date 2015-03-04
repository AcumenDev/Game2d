#include <UpdateEventDto.hpp>
#include "SceneManager.hpp"
SceneManager::SceneManager(
        SDL_Renderer* renderer,
        shared_ptr<b2World> physicWorld,
        shared_ptr<NotificationServices> notificationServices) {
    _renderer = renderer;
    _notificationServices = notificationServices;
    _physicWorld = physicWorld;
}

SceneManager::~SceneManager() {
}

shared_ptr<SceneNode> SceneManager::AddChildNode(string name) {
    auto childNode = std::make_shared<SceneNode>(name);
    _childNodes.push_back(childNode);
    return childNode;
}

void SceneManager::Draw() {
    for(const auto & node : _childNodes) {
        node->Draw();
    }

    if(_sceneManagerFpsCounterBase) {
        _sceneManagerFpsCounterBase->Update(_fps_current);
    }
    _calcFps();
    _physicWorld->DrawDebugData();
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


void SceneManager::Update(float delta, shared_ptr<EventInputSystem> eventInputSystem) {
    for(const auto & node : _childNodes) {
        node->Update(UpdateEventDto(delta, _notificationServices, eventInputSystem));
    }
//1.0f/60.0f
    _physicWorld->Step(delta, 6, 4);


}
void SceneManager::SetFpsListener(shared_ptr<SceneManagerFpsCounterBase> sceneManagerFpsCounterBase) {
    _sceneManagerFpsCounterBase = sceneManagerFpsCounterBase;
}

