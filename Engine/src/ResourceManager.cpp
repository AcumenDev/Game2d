#include "ResourceManager.hpp"

ResourceManager::ResourceManager() {
    //ctor
}

ResourceManager::~ResourceManager() {
    //dtor
}

Texture * ResourceManager::GetTextureFromFile(SDL_Renderer* render, std::string path) {
    SDL_Texture* newTexture = IMG_LoadTexture(render, path.c_str()) ;
    Texture * texture = nullptr;
    if( newTexture == nullptr ) {
        Logger * logger=new Logger();
        logger->Info("Unable to load image "+path+" SDL_image Error: "+IMG_GetError());
        delete logger;
    } else {
        int w, h;
        SDL_QueryTexture(newTexture, NULL, NULL, &w, &h);
        texture =  new Texture(render, newTexture, w, h);
    }
    return texture;
}
