#include "EventInputSystem.hpp"
EventInputSystem::EventInputSystem() {
}


void EventInputSystem::Update(SDL_Event event) {
    this->event = event;
}

EventInputSystem::~EventInputSystem() {
}

bool EventInputSystem::IsJump() const {
    return checkInpunt(SDLK_UP);
}

bool EventInputSystem::IsLeft() const {
    return checkInpunt(SDLK_LEFT);
}

bool EventInputSystem::IsRight() const {
    return checkInpunt(SDLK_RIGHT);
}


bool EventInputSystem::IsShot() const {
    return checkInpunt(SDLK_SPACE);
}

IPoint EventInputSystem::getMousePosition()
{
    switch (event.type) {
        case SDL_MOUSEMOTION : {
            _mousePosition = IPoint(event.motion.x,event.motion.y);
            return _mousePosition;
        }
        default:
            return _mousePosition;
    }

}

bool EventInputSystem::checkInpunt(SDL_Keycode keycode)const {
    switch (event.type) {
        case SDL_KEYDOWN : {
            if (event.key.keysym.sym == keycode) {
                return true;
            }
        }
    }
    return false;
}

