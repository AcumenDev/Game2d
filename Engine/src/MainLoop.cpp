#include "MainLoop.hpp"

MainLoop::MainLoop(std::shared_ptr<SceneManager> sceneManager, std::shared_ptr<Logger> log) {
    _sceneManager = sceneManager;
    _log = log;
}

void MainLoop::Draw() {
    _sceneManager->Draw();
}

void MainLoop::CheckInput() {
    SDL_Event  event;
    if( SDL_PollEvent( &event ) == 0 ) {
        return;
    }

    switch(event.type) {
    case SDL_QUIT : {
        Stop();
        break;
    }
    }
    _currentEventInputSystem = std::make_shared<EventInputSystem>(event);
}

void MainLoop::Update(float delta) {
    _sceneManager->Update(delta, _currentEventInputSystem );
}

void MainLoop::Start() {
    _currentTime = (float)SDL_GetTicks();
    _run = true;
    while(_run) {
        UpdateDeltaTime();
        CheckInput();
        Update(_GetDeltaTime());
        Draw();
    }
}

void MainLoop::Stop() {
    _run = false;
}

void MainLoop::UpdateDeltaTime() {
    auto nowTime =  (float)SDL_GetTicks();
    _deltaTime = nowTime - _currentTime;
    _currentTime = nowTime;
}

float MainLoop::_GetDeltaTime() {
    return _deltaTime;
}
