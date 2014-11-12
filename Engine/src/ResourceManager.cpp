#include "ResourceManager.hpp"

ResourceManager::ResourceManager(std::shared_ptr<Logger> log) {
    _log = log;
}

ResourceManager::~ResourceManager() {
    //dtor
}

std::shared_ptr<Texture> ResourceManager::GetTextureFromFile(SDL_Renderer* render, std::string path) {
    SDL_Texture* newTexture = IMG_LoadTexture(render, path.c_str()) ;
    std::shared_ptr<Texture>  texture ;
    if( newTexture == nullptr ) {

        _log->Error("Unable to load image "+path+" SDL_image Error: "+IMG_GetError());
    } else {
        int w, h;
        SDL_QueryTexture(newTexture, NULL, NULL, &w, &h);
        texture =  std::make_shared<Texture>(render, newTexture, w, h);
    }
    return texture;
}
