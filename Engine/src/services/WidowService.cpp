#include "services/WidowService.hpp"

WidowService::WidowService(std::shared_ptr<Logger> log) {
    _log = log;
}

WidowService::~WidowService() {
}

std::shared_ptr<Window> WidowService::Create(std::string title, int x, int y, int w, int h) {
    SDL_Window * gWindow = SDL_CreateWindow(title.c_str(), x, y, w, h, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if( gWindow == nullptr ) {
        _log-> Error("Window could not be created! SDL Error: "+ std::string(SDL_GetError()));
        return nullptr;
    }

    SDL_Renderer * gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( gRenderer == nullptr ) {
        _log-> Error("Renderer could not be created! SDL Error: "+ std::string(SDL_GetError()));
        return nullptr;
    }

    SDL_GLContext  glContext  =  SDL_GL_CreateContext(gWindow);
    if( glContext == nullptr ) {
        _log-> Error("GLContext could not be created! SDL Error: "+ std::string(SDL_GetError()));
        return nullptr;
    }
    return std::make_shared<Window>(gWindow, gRenderer, glContext);
}
