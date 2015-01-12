#include "ResourceManager.hpp"

ResourceManager::ResourceManager(std::shared_ptr<Logger> log, SDL_Renderer* render)
        :_name("ResourceManager"), _log(log), _render(render) {}

ResourceManager::~ResourceManager() {
}

std::shared_ptr<Texture> ResourceManager::GetTextureFromFile(std::string path) {
    _log->Debug(_name, "Loaded texture from file: "+ path);
    SDL_Texture* newTexture = IMG_LoadTexture(_render, path.c_str()) ;
    std::shared_ptr<Texture>  texture ;
    if( newTexture == nullptr ) {
        _log->Error(_name, "Unable to load image "+path+" SDL_image Error: "+IMG_GetError());
    } else {
        int w, h;
        SDL_QueryTexture(newTexture, NULL, NULL, &w, &h);
        texture =  std::make_shared<Texture>(_render, newTexture, w, h);
    }
    return texture;
}


vector<shared_ptr<Texture>> ResourceManager::GetTexturesFromFile(string path, vector<FRectangle> rectangls) {


   // return std::vector<shared_ptr<Texture>, allocator < shared_ptr<Texture>> > ();
}
