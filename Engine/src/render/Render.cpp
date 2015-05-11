#include "render/Render.hpp"

shared_ptr<Render> Render::_render = nullptr;


Render::Render(SDL_Renderer *renderer, shared_ptr<Camera> camera) {
    _className = "Render";
    Logger::Get()->Debug(_className, "Init render");
    _camera = camera;
    _sdlRender = renderer;
}

void  Render::Init(SDL_Renderer *renderer, shared_ptr<Camera> camera) {
    if (!_render) {
        _render.reset(new Render(renderer, camera));
    }
}

void Render::RenderTexture(SDL_Texture *texture, Utils::IRectangle rectangle) {
    SDL_Rect renderQuad = {rectangle.LeftTop.x, rectangle.LeftTop.y, rectangle.RightBottom.x, rectangle.RightBottom.y};
    if (_camera && !_localFixed) {
        FPoint positionCamera = _camera->GetPosition();
        renderQuad.x += positionCamera.x;
        renderQuad.y += positionCamera.y;
    }

    SDL_RenderCopy(_sdlRender, texture, NULL, &renderQuad);
}

void Render::DrawLines(vector<SDL_Point> points) {

    FPoint positionCamera = _camera->GetPosition();

    for (auto &item : points) {
        item.x += positionCamera.x;
        item.y += positionCamera.y;
    }

    SDL_RenderDrawLines(_sdlRender, points.data(), points.size());
}

void Render::DrawLine(FPoint point1, FPoint point2) {
    FPoint positionCamera = _camera->GetPosition();
    SDL_RenderDrawLine(_sdlRender, point1.x + positionCamera.x, point1.y + positionCamera.y,
                       point2.x + positionCamera.x, point2.y + positionCamera.y);
}

shared_ptr<Render> Render::Get() {
    if (!_render) {
        Logger::Get()->Error("Render", "Render not created!");
    }
    return _render;
}

shared_ptr<Camera> Render::GetCamera() {
    return _camera;
}

void Render::SetRenderDrawColor(float r, float g, float b, float a) {
    SDL_SetRenderDrawColor(_sdlRender, (int) r * 255, (int) g * 255, (int) b * 255, (int) a * 255);
}

FPoint Render::ToWorldCoordinate(FPoint point) {
    FPoint positionCamera = _camera->GetPosition();
    return FPoint(point.x - positionCamera.x, point.y - positionCamera.y);
}

IPoint Render::ToWorldCoordinate(IPoint point) {
    FPoint positionCamera = _camera->GetPosition();
    return IPoint(point.x - positionCamera.x, point.y - positionCamera.y);
}

FPoint Render::ToLocalCoordinate(FPoint point) {
    FPoint positionCamera = _camera->GetPosition();
    return FPoint(point.x + positionCamera.x, point.y + positionCamera.y);
}

void Render::RenderTolocal() {
    _localFixed = true;
}

void Render::RenderToGlobal() {
    _localFixed = false;
}

void Render::RenderClear() {
    SDL_RenderClear(_sdlRender);
}

void Render::RenderPresent() {
    SDL_RenderPresent(_sdlRender);
}
