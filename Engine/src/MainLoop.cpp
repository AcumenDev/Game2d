#include "MainLoop.hpp"

MainLoop::MainLoop(std::shared_ptr<SceneManager> sceneManager) {
    _sceneManager = sceneManager;
    _className = "MainLoop";
}

MainLoop::~MainLoop() {

}

void MainLoop::Draw() {
    _sceneManager->Draw();
}

void MainLoop::CheckInput() {
    SDL_Event event;
    if (SDL_PollEvent(&event) == 0) {
        return;
    }

    switch (event.type) {
        case SDL_QUIT : {
            Stop();
            break;
        }
    }
    _currentEventInputSystem->Update(event);
}

void MainLoop::Update(float delta) {
    _sceneManager->Update(delta, _currentEventInputSystem);
}

int MainLoop::Start() {
    _run = true;
    _currentEventInputSystem = make_shared<EventInputSystem>();

    unsigned nextGameTick = SDL_GetTicks();
    int loops;

    while (_run) {

        loops = 0;
        while (SDL_GetTicks() > nextGameTick && loops < MAX_FRAME_SKIP) {
            UpdateDeltaTime();
            _updateGame();

            nextGameTick += SKIP_TICKS;
            loops++;
        }

        Draw();
    }
    return 0;
}

void MainLoop::_updateGame() {

    CheckInput();
    Update(_GetDeltaTime());
}

void MainLoop::Stop() {
    Logger::Get()->Debug(_className, "Stopping");
    _run = false;
}

void MainLoop::UpdateDeltaTime() {
    auto nowTime = (float) SDL_GetTicks();
    _deltaTime = (nowTime - _currentTime) / 1000;
    _currentTime = nowTime;
}

float MainLoop::_GetDeltaTime() {
    return _deltaTime;
}
