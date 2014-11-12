#ifndef WINDOW_H
#define WINDOW_H
#include "SDL.h"
class Window {
public:
    Window(SDL_Window * window, SDL_Renderer * render, SDL_GLContext  glContext);
    virtual ~Window();
    SDL_Renderer * GetRenderer();
protected:
private:
    SDL_Window * _window;
    SDL_Renderer * _render;
    SDL_GLContext  _glContext;
};
#endif // WINDOW_H
