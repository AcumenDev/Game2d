#include "MainLoop.hpp"

MainLoop::MainLoop() {
}

MainLoop::~MainLoop() {
}

void MainLoop::Start() {
    _currentTime =  SDL_GetTicks();
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

void MainLoop::Draw() {
}

void MainLoop::CheckInput() {
}

void MainLoop::Update(float delta) {
}

void MainLoop::UpdateDeltaTime() {
    auto nowTime =  SDL_GetTicks();
    _deltaTime = nowTime - _currentTime;
    _currentTime = nowTime;
}

float MainLoop::_GetDeltaTime() {
    return _deltaTime;
}
