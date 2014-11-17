#include "ShowFps.hpp"
ShowFps::ShowFps(std::shared_ptr<Logger> log, SDL_Renderer* render, std::string path, int size, IPoint iPoint, int styleFont)
    :Font(log,render,path,size,iPoint, styleFont) {
}

ShowFps::~ShowFps() {

}

void ShowFps::Update(int fps) {
    SetText(std::to_string(fps)+ " FPS");
}
