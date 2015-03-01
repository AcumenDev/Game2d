#ifndef EVENTINPUTSYSTEM_H
#define EVENTINPUTSYSTEM_H

#include "SDL.h"

class EventInputSystem {
public:
    EventInputSystem(SDL_Event event);

    virtual ~EventInputSystem();

    bool IsJump() const;

    bool IsLeft() const;

    bool IsRight() const;


    SDL_Event event;
protected:
private:
    bool checkInpunt(SDL_Keycode keycode) const;

};

#endif // EVENTINPUTSYSTEM_H
