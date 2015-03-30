#ifndef EVENTINPUTSYSTEM_H
#define EVENTINPUTSYSTEM_H


#include "SDL.h"
#include "Utils/Point.hpp"

using namespace Utils;

class EventInputSystem {
public:

    EventInputSystem() ;


    void Update(SDL_Event event);

    virtual ~EventInputSystem();

    bool IsJump() const;

    bool IsLeft() const;

    bool IsRight() const;

    IPoint getMousePosition();


    SDL_Event event;
protected:
private:
    bool checkInpunt(SDL_Keycode keycode) const;
    IPoint _mousePosition;

};

#endif // EVENTINPUTSYSTEM_H
