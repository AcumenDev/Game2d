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

void Camera::ShowSizeVieport() {
    SDL_Rect rect;
    SDL_RenderGetViewport(_renderer, &rect);

    Logger::Get()->Debug(_className, string(
            "Size vieport x: " + std::to_string(rect.x)
                    + " y: " + std::to_string(rect.y)
                    + " h: " + std::to_string(rect.h)
                    + " w: " + std::to_string(rect.w)));
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