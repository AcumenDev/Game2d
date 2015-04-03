#ifndef MAINLOOP_H
#define MAINLOOP_H

#include "SDL.h"
#include "SceneManager.hpp"
#include "EventInputSystem.hpp"

using std::shared_ptr;

class MainLoop {
public:
    MainLoop(shared_ptr<SceneManager> sceneManager);

    virtual ~MainLoop();

    void Start();

    void Stop();

    virtual void Draw();

    virtual void CheckInput();

    virtual void Update(float delta);

    virtual void UpdateDeltaTime();

protected:
    float _GetDeltaTime();

private:
    float _deltaTime;
    float _currentTime;
    mutable bool _run;
    shared_ptr<SceneManager> _sceneManager;
    shared_ptr<EventInputSystem> _currentEventInputSystem;

    void _updateGame();

    const unsigned TICKS_PER_SECOND = 100;
    const unsigned SKIP_TICKS = 1000 / TICKS_PER_SECOND;
    const unsigned MAX_FRAME_SKIP = 10;
};

#endif // MAINLOOP_H
