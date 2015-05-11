#include "SceneManager.hpp"

SceneManager::SceneManager(
        shared_ptr<b2World> physicWorld,
        shared_ptr<NotificationServices> notificationServices,
        shared_ptr<DebugEngineBase> debugEngineBase) {
    _notificationServices = notificationServices;
    _physicWorld = physicWorld;
    _debugEngineBase = debugEngineBase;
}

SceneManager::~SceneManager() {
    _childNodes.clear();
}

shared_ptr<SceneNode> SceneManager::AddChildNode(string name, bool fixedCord) {
    auto childNode = std::make_shared<SceneNode>(name, fixedCord);
    _childNodes.push_back(childNode);
    return childNode;
}

void SceneManager::Draw() {
    _debugEngineBase->SetRenderTime(calkTimeExecute([this] {
        Render::Get()->SetRenderDrawColor(1, 1, 1, 1);
        Render::Get()->RenderClear();
        for (const auto &node : _childNodes) {
            node->Draw();
        }
        _physicWorld->DrawDebugData();
        _calcFps();
        Render::Get()->RenderPresent();

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
        if (_sceneController) {
            _sceneController->Update(eventInputSystem);
        }
    }));
}

void SceneManager::SetController(shared_ptr<SceneController> sceneController) {
    _sceneController = sceneController;
    _sceneController->SetSceneManager(shared_from_this());
}

bool SceneManager::DeleteObjectForId(unsigned int objectId) {
    for (const auto &node : _childNodes) {
        if (node->DeleteObjectForId(objectId)) {
            return true;
        }
    }
    return false;
}
