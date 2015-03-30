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
    Camera();

    void SetPosition(FPoint point);

    FPoint GetPosition();

    void ShowSizeVieport();

    void MoveToLeft(float x);

    void MoveToRight(float x);

    void MoveToUp(float y);

    void MoveToDown(float y);

    ~Camera();

private:
    SDL_Renderer *_renderer;
    string _className;
    FPoint _point;
};

#endif