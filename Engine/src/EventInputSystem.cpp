#include "EventInputSystem.hpp"

EventInputSystem::EventInputSystem(SDL_Event event) {
    this->event = event;
}

EventInputSystem::~EventInputSystem() {
}
