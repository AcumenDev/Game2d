#ifndef RENDER_HPP
#define RENDER_HPP

#include <memory>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "Utils/Rectangle.hpp"
#include "Utils/Point.hpp"
#include "render/Camera.hpp"

using Utils::FPoint;
using std::shared_ptr;
using std::string;
using std::vector;

class Render {

public:
    static shared_ptr<Render> Get();

    static void Init(SDL_Renderer *renderer, shared_ptr<Camera> camera);

    void RenderTexture(SDL_Texture *texture, Utils::IRectangle rectangle);

    void DrawLines(vector<SDL_Point> points);

    void DrawLine(FPoint point1, FPoint point2);

    void SetRenderDrawColor(float r, float g, float b, float a);

    shared_ptr<Camera> GetCamera();

    void RenderClear();

    void RenderPresent();

    FPoint ToWorldCoordinate(FPoint point);

    IPoint ToWorldCoordinate(IPoint point);

    ////todo обобщить
    FPoint ToLocalCoordinate(FPoint point);

    void RenderTolocal();

    void RenderToGlobal();

private:
    Render(SDL_Renderer *renderer, shared_ptr<Camera> camera);

    Render() {
        _localFixed = false;
    }

    Render(const Render &) {
    };

    Render &operator=(Render &) {
    };
    SDL_Renderer *_sdlRender;
    shared_ptr<Camera> _camera;
    static shared_ptr<Render> _render;
    string _className;

    bool _localFixed;

};


#endif