#include "ResourceManager.hpp"

ResourceManager::ResourceManager(std::shared_ptr<Logger> log, SDL_Renderer *render)
        : _name("ResourceManager"), _log(log), _render(render) {
}

ResourceManager::~ResourceManager() {
}

std::shared_ptr<Texture> ResourceManager::GetTextureFromFile(std::string path) {
    _log->Debug(_name, "Loaded texture from file: " + path);
    SDL_Texture *newTexture = IMG_LoadTexture(_render, path.c_str());
    std::shared_ptr<Texture> texture;
    if (newTexture == nullptr) {
        _log->Error(_name, "Unable to load image " + path + " SDL_image Error: " + IMG_GetError());
    } else {
        int w, h;
        SDL_QueryTexture(newTexture, NULL, NULL, &w, &h);
        texture = std::make_shared<Texture>(_render, newTexture, w, h);
    }
    return texture;
}

SDL_Surface *ResourceManager::loadSurfaceFromFile(string path) {
    _log->Debug(_name, "Loaded textures from file: " + path);
    SDL_Surface *surface = IMG_Load(path.c_str());

    if (surface == nullptr) {
        _log->Error(_name, "Unable to load image " + path + " SDL_image Error: " + IMG_GetError());
        return surface;
    }
    return surface;
}

vector<shared_ptr<Texture>> ResourceManager::GetTexturesFromFile(string path, vector<IRectangle> rectangls) {
    auto surface = loadSurfaceFromFile(path);
    vector<shared_ptr<Texture>> result;
    if (surface == nullptr) {
        return result;
    }
    int count = 1;
    for (const auto &item : rectangls) {
        SDL_Surface *surfaceTemp = SDL_CreateRGBSurface(0, item.RightBottom.x, item.RightBottom.y,
                surface->format->BitsPerPixel,
                surface->format->Rmask,
                surface->format->Gmask,
                surface->format->Bmask,
                surface->format->Amask
        );

        SDL_Rect sdl_rect;
        sdl_rect.x = item.LeftTop.x;
        sdl_rect.y = item.LeftTop.y;
        sdl_rect.h = item.RightBottom.y;
        sdl_rect.w = item.RightBottom.x;

        SDL_BlitSurface(surface, &sdl_rect, surfaceTemp, NULL);
        //  IMG_SavePNG(surface, string("debug/all.png").c_str());
        //  IMG_SavePNG(surfaceTemp, string("debug/" + std::to_string(count) + ".png").c_str());

        SDL_Texture *sdl_texture = SDL_CreateTextureFromSurface(_render, surfaceTemp);
        int w, h;
        SDL_QueryTexture(sdl_texture, NULL, NULL, &w, &h);
        std::shared_ptr<Texture> texture = std::make_shared<Texture>(_render, sdl_texture, w, h);
        result.push_back(texture);

        SDL_FreeSurface(surfaceTemp);
        count++;
    }
    SDL_FreeSurface(surface);

    return result;
}
