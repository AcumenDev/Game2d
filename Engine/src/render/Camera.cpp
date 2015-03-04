#include "render/Camera.hpp"

Camera::Camera(SDL_Renderer *renderer) {
    _renderer = renderer;
    _className = "Camera";
}

void Camera::SetPosition(IPoint point) {
    SDL_Rect rect;
    SDL_RenderGetViewport(_renderer, &rect);

    rect.x+=point.x;
    rect.y+=point.y;
    rect.w+=point.x;
    rect.h+=point.y;

    SDL_RenderSetViewport(_renderer, &rect);

    // SDL_RenderSetViewport
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
