#include "SceneManager.hpp"

SceneManager::SceneManager(
        SDL_Renderer *renderer,
        shared_ptr<b2World> physicWorld,
        shared_ptr<NotificationServices> notificationServices,
        shared_ptr<DebugEngineBase> debugEngineBase) {
    _renderer = renderer;
    _notificationServices = notificationServices;
    _physicWorld = physicWorld;
    _debugEngineBase = debugEngineBase;
}

SceneManager::~SceneManager() {
}

shared_ptr<SceneNode> SceneManager::AddChildNode(string name, bool fixedCord) {
    auto childNode = std::make_shared<SceneNode>(name, fixedCord);
    _childNodes.push_back(childNode);
    return childNode;
}

void SceneManager::Draw() {
    _debugEngineBase->SetRenderTime( calkTimeExecute([this] {
            SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);

            SDL_RenderClear(_renderer);
            for (const auto &node : _childNodes) {
                node->Draw();
            }


            _physicWorld->DrawDebugData();
            _calcFps();
            SDL_RenderPresent(_renderer);
        }));
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
    _debugEngineBase->SetUpdateTime(calkTimeExecute([this, delta, eventInputSystem] {
        auto updateEventDto = UpdateEventDto(delta, _notificationServices, eventInputSystem);
        for (const auto &node : _childNodes) {
            node->Update(updateEventDto);
        }

        _physicWorld->Step(delta, 6, 4);  //1.0f/60.0f

        _debugEngineBase->SetFps(_fps_current);
        _debugEngineBase->Update(updateEventDto);
    }));
}