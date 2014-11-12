#include "Window.hpp"

Window::~Window() {
    SDL_DestroyRenderer( _render );
    SDL_DestroyWindow( _window );
    SDL_GL_DeleteContext(_glContext);
}

Window::Window(SDL_Window * window, SDL_Renderer * render, SDL_GLContext glContext) {
    _window = window;
    _render = render;
    _glContext = glContext;
}

SDL_Renderer * Window::GetRenderer() {
    return _render;
}
