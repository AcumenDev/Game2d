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
    Camera(int width, int height);

    void SetPosition(FPoint point);
    void SetSizeMap(int width, int height);

    FPoint GetPosition();

    void CenterToPoint(FPoint point);

    ~Camera();

private:
    string _className;
    FPoint _point;

    int _width;
    int _height;

    int _mapWidth;
    int _mapHeight;

    float _speedCamera;
};

#endif