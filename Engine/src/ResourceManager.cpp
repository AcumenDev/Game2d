#include "ResourceManager.hpp"

ResourceManager::ResourceManager() {
    //ctor
}

ResourceManager::~ResourceManager() {
    //dtor
}

std::shared_ptr<Texture> ResourceManager::GetTextureFromFile(SDL_Renderer* render, std::string path) {
    SDL_Texture* newTexture = IMG_LoadTexture(render, path.c_str()) ;
    std::shared_ptr<Texture>  texture ;
    if( newTexture == nullptr ) {
        std::shared_ptr<Logger>  logger= std::make_shared<Logger>();
        logger->Info("Unable to load image "+path+" SDL_image Error: "+IMG_GetError());
    } else {
        int w, h;
        SDL_QueryTexture(newTexture, NULL, NULL, &w, &h);
        texture =  std::make_shared<Texture>(render, newTexture, w, h);
    }
    return texture;
}
