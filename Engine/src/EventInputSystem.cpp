#include "EventInputSystem.hpp"

EventInputSystem::EventInputSystem(SDL_Event event) {
    this->event = event;
}

EventInputSystem::~EventInputSystem() {
}

bool EventInputSystem::IsJump() const {
    return checInpunt(SDLK_UP);
}

bool EventInputSystem::IsLeft() const {
    return checInpunt(SDLK_LEFT);
}

bool EventInputSystem::IsRight() const {
    return checInpunt(SDLK_RIGHT);
}

bool EventInputSystem::checInpunt(SDL_Keycode keycode)const {
    switch (event.type) {
        case SDL_KEYDOWN : {
            if (event.key.keysym.sym == keycode) {
                return true;
            }
        }
    }
    return false;
}

