#include "InitService.hpp"
InitService::InitService(std::shared_ptr<Logger> log) {
    _log = log;
}

bool InitService::Init() {
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
        _log-> Error("SDL could not initialize! SDL Error: "+ std::string(SDL_GetError()));
        return false;
    }

    int imgFlags  = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP;
    if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
        _log-> Error("SDL_image could not initialize! SDL_image Error: "+ std::string(SDL_GetError()));
        return false;
    }

    if(!TTF_WasInit() && TTF_Init()==-1) {
        _log-> Error("Error: SDL_ttf not initialize! "+ std::string(TTF_GetError()));
        return false;
    }

    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
        _log-> Warn("Warning: Linear texture filtering not enabled! "+ std::string(SDL_GetError()));
    }
    return true;
}

InitService::~InitService() {
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}
