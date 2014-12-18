#include "ObjectsDrawing/Utils/ShowFps.hpp"

ShowFps::ShowFps(std::shared_ptr<Logger> log, SDL_Renderer* render, std::string path, int size, FPoint point, int styleFont)
    :Font(log,render,path,size, point, styleFont) {
}

ShowFps::~ShowFps() {

}

void ShowFps::Update(int fps) {
    SetText(std::to_string(fps)+ " FPS");
}
