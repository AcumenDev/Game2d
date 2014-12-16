#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include "Utils/IPoint.hpp"
#include "Utils/FPoint.hpp"

class Texture {
public:
    Texture(SDL_Renderer* render, SDL_Texture* texture, int w, int h);
    ~Texture();
    void free();
    void Draw(IPoint iPoint);
    void Draw(FPoint iPoint);
    int getWidth();
    int getHeight();
private:
    SDL_Texture* _texture;
    SDL_Renderer* _render;
    int _h;
    int _w;
};
#endif // TEXTURE_H
