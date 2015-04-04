#include "render/Camera.hpp"

Camera::Camera(int width, int height) :
        _className("Camera"),
        _width(width),
        _height(height), _speedCamera(3.5f) { }

void Camera::SetPosition(FPoint point) {
    _point = point;
}


void Camera::SetSizeMap(int width, int height) {
    _mapWidth = width;
    _mapHeight = height;
}

FPoint Camera::GetPosition() {
    return _point;
}

Camera::~Camera() {
}

void Camera::CenterToPoint(FPoint point) {

//TODO Сделать чтобы камера не уходила за размер карты
    FPoint targetPoint;

    targetPoint.x = point.x - _width / 3;
    targetPoint.y = point.y - _height / 2;

    float interval = _width / 100;

    if (-_point.x <= (targetPoint.x - interval)) {
        _point.x -= _speedCamera;
    }
    else if (-_point.x >= (targetPoint.x + interval)) {
        _point.x += _speedCamera;
    }

    if (-_point.y <= (targetPoint.y - interval)) {
        _point.y -= _speedCamera;
    }
    else if (-_point.y >= (targetPoint.y + interval)) {
        _point.y += _speedCamera;
    }
}
