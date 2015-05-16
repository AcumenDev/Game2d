#ifndef EVENTINPUTSYSTEM_H
#define EVENTINPUTSYSTEM_H

#include <SDL.h>
#include "Utils/Point.hpp"

using namespace Utils;

class EventInputSystem {
public:

    EventInputSystem();

    void Update(SDL_Event event);

    virtual ~EventInputSystem();

    bool IsRestartPlayer() const;

    bool IsJump() const;

    bool IsLeft() const;

    bool IsRight() const;

    bool IsShot() const;

    IPoint getMousePosition();

    SDL_Event GetEvent();

private:
    SDL_Event _event;
    IPoint _mousePosition;

    bool _checkInpunt(SDL_Keycode keycode) const;
};

#endif // EVENTINPUTSYSTEM_H
