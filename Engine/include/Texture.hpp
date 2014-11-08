#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
class Texture {
public:
    Texture();
    ~Texture();
    void Init(SDL_Renderer* render);
    bool loadFromFile(std::string path );
    void free();
    void render(int x, int y );
    int getWidth();
    int getHeight();
private:
    SDL_Texture* _texture;
    SDL_Renderer* _render;
    int mWidth;
    int mHeight;
};
#endif // TEXTURE_H
