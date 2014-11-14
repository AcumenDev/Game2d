#ifndef EVENTINPUTSYSTEM_H
#define EVENTINPUTSYSTEM_H
#include "SDL.h"
class EventInputSystem {
public:
    EventInputSystem(SDL_Event event);
    virtual ~EventInputSystem();
    SDL_Event event;
protected:
private:

};
#endif // EVENTINPUTSYSTEM_H
