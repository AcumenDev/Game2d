#include "resourceManagers/TexturesResourceManager.hpp"

TexturesResourceManager::TexturesResourceManager(SDL_Renderer *render)
        : _name("TexturesResourceManager"), _render(render) {
}

TexturesResourceManager::~TexturesResourceManager() {
}

std::shared_ptr<Texture> TexturesResourceManager::getResourse(std::string path) {
    Logger::Get()->Debug(_name, "Loaded texture from file: " + path);
    SDL_Texture *newTexture = IMG_LoadTexture(_render, path.c_str());
    std::shared_ptr<Texture> texture;
    if (newTexture == nullptr) {
        Logger::Get()->Error(_name, "Unable to load image " + path + " SDL_image Error: " + IMG_GetError());
    } else {
        int w, h;
        SDL_QueryTexture(newTexture, NULL, NULL, &w, &h);
        texture = std::make_shared<Texture>(_render, newTexture, w, h);
    }
    return texture;
}
