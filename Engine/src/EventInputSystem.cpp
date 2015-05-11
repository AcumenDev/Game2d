#include "EventInputSystem.hpp"

EventInputSystem::EventInputSystem() {
}

void EventInputSystem::Update(SDL_Event event) {
    this->_event = event;
}

EventInputSystem::~EventInputSystem() {
}

bool EventInputSystem::IsJump() const {
    return _checkInpunt(SDLK_UP);
}

bool EventInputSystem::IsLeft() const {
    return _checkInpunt(SDLK_LEFT);
}

bool EventInputSystem::IsRight() const {
    return _checkInpunt(SDLK_RIGHT);
}

bool EventInputSystem::IsShot() const {
    return _checkInpunt(SDLK_SPACE);
}

IPoint EventInputSystem::getMousePosition() {
    switch (_event.type) {
        case SDL_MOUSEMOTION : {
            _mousePosition = IPoint(_event.motion.x, _event.motion.y);
            return _mousePosition;
        }
        default:
            return _mousePosition;
    }
}

bool EventInputSystem::_checkInpunt(SDL_Keycode keycode) const {
    switch (_event.type) {
        case SDL_KEYDOWN : {
            if (_event.key.keysym.sym == keycode) {
                return true;
            }
        }
    }
    return false;
}

SDL_Event EventInputSystem::GetEvent() {
    return _event;
}

bool EventInputSystem::IsRestartPlayer() const {
    return _checkInpunt(SDLK_r);
}
