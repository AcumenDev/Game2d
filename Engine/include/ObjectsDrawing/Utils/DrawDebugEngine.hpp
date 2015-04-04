#ifndef DRAWDEBUGENGINE_HPP_
#define DRAWDEBUGENGINE_HPP_

#include <numeric>
#include <string>
#include <functional>
#include "Utils/debugEngine/DebugEngineBase.hpp"
#include "ObjectsDrawing/ObjectDrawingBase.hpp"
#include "ObjectsDrawing/Font.hpp"

using namespace Graphic;

class DrawDebugEngine
        : public ObjectDrawingBase,
          public DebugEngineBase { //Вывод координат мыши в локальных и мировых, количествой обьектов на сцене
public:
    DrawDebugEngine(shared_ptr<Font> _font);

    virtual  ~DrawDebugEngine();

    virtual void SetPosition(FPoint const &fPoint) override;

    virtual void Draw() override;

    virtual void Update(UpdateEventDto updateEventDto) override;

    virtual void SetFps(int fps);


    virtual void SetRenderTime(long long time) override;

    virtual void SetUpdateTime(long long time) override;

private:
    void _linearInterpolation(vector<long long> values, float &outTime, int step);

    IPoint _mousePoint;
    shared_ptr<Font> _font;
    string _fps;

    vector<long long> _renderTimes;
    vector<long long> _updateTimes;
    float _renderTime;
    float _updateTime;

    int _fpsCount;
};

#endif //DRAWDEBUGENGINE_HPP_



