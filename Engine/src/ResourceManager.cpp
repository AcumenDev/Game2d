#include "ResourceManager.hpp"

ResourceManager::ResourceManager() {
    //ctor
}

ResourceManager::~ResourceManager() {
    //dtor
}

Texture * ResourceManager::GetTextureFromFile(SDL_Renderer* render, std::string path) {
    Logger * logger=new Logger();
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    Texture* texture;
    if( loadedSurface == NULL ) {
        logger->Info("Unable to load image "+path+" SDL_image Error: "+IMG_GetError());
    } else {
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
        newTexture = SDL_CreateTextureFromSurface(render, loadedSurface );
        if( newTexture == NULL ) {
            logger->Info("Unable to create texture from "+path+" SDL Error: "+SDL_GetError());
        }

        texture =  new Texture(render, newTexture, loadedSurface->w, loadedSurface->h);
        SDL_FreeSurface( loadedSurface );
    }
    delete logger;
    return texture;
}
