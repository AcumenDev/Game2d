//
// Created by akum on 23.03.2015.
//

#include "ObjectsDrawing/Utils/DrawDebugEngine.hpp"

DrawDebugEngine::DrawDebugEngine(shared_ptr<Font> debugFont) : _font(debugFont) {
    _mousePoint = IPoint(0, 0);
    _renderTime = 0;
    _updateTime = 0;
    _fpsCount = 0;
}

DrawDebugEngine::~DrawDebugEngine() {

}


void DrawDebugEngine::SetPosition(FPoint const &fPoint) {

}

void DrawDebugEngine::Draw() {
    _font->Draw();
}

void DrawDebugEngine::Update(UpdateEventDto updateEventDto) {

    _mousePoint = updateEventDto.eventInputSystem->getMousePosition();
    IPoint globalCord = Render::Get()->ToWorldCoordinate(_mousePoint);
    string totalDebugInfo = _fps
            + "\nRender time:" + std::to_string(_renderTime)
            + "\nUpdate time:" + std::to_string(_updateTime)
            + "\nMouse positin local\n" + _mousePoint.toString()
            + "\n world\n" + globalCord.toString();
    _font->SetText(totalDebugInfo, 200);
}

void DrawDebugEngine::SetFps(int fps) {
    if (_fpsCount == fps) {
        return;
    }
    _fpsCount = fps;
    _fps = std::to_string(_fpsCount) + " FPS";
}

void DrawDebugEngine::SetRenderTime(long long time) {
    _renderTimes.push_back(time);
    _linearInterpolation(_renderTimes, _renderTime,2000);
}

void DrawDebugEngine::SetUpdateTime(long long time) {
    _updateTimes.push_back(time);
    _linearInterpolation(_updateTimes, _updateTime,500);
}

void DrawDebugEngine::_linearInterpolation(vector<long long> values, float &outTime, int step) {
    if (values.size() > step) {
        outTime = std::accumulate(values.begin(), values.end(), 0)/(float)values.size();
        values.clear();
    }
}
