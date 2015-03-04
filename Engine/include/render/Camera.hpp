#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <iostream>
#include <SDL_render.h>
#include "Utils/logger/Logger.hpp"
#include "Utils/Point.hpp"


using std::string;
using namespace Utils;

class Camera {

public:
    Camera(SDL_Renderer *renderer);

    void SetPosition(IPoint point);

    void ShowSizeVieport();

    ~Camera();

private:
    SDL_Renderer *_renderer;
    string _className;
};

#endif