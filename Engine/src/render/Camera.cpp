#include "render/Camera.hpp"

Camera::Camera() {
    _className = "Camera";
}

void Camera::SetPosition(FPoint point) {
    _point = point;
}

FPoint Camera::GetPosition() {
    return _point;
}

Camera::~Camera() {
}


void Camera::MoveToLeft(float x) {
    _point.x += x;
}

void Camera::MoveToRight(float x) {
    _point.x -= x;
}

void Camera::MoveToUp(float y) {
    _point.x -= y;
}

void Camera::MoveToDown(float y) {
    _point.x += y;
}

void Camera::CetnrToPoint(FPoint point) {
    unsigned witch = 640;
    unsigned heich = 480;

//todo Передавать размер камеры и размер карты
    FPoint targetPoint;

    targetPoint.x = point.x - witch / 3;
    targetPoint.y = point.y - heich / 2;

    float intervalWidtch = witch / 100;

    float coff = 3.5f;

    if (-_point.x <= (targetPoint.x - intervalWidtch)) {
        _point.x -= coff;
    }
    else if (-_point.x >= (targetPoint.x + intervalWidtch)) {
        _point.x += coff;
    }


    if (-_point.y <= (targetPoint.y - intervalWidtch)) {
        _point.y -= coff;
    }
    else if (-_point.y >= (targetPoint.y + intervalWidtch)) {
        _point.y += coff;
    }
}
