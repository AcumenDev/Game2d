#ifndef MAINLOOP_H
#define MAINLOOP_H
#include "SDL.h"
#include "SceneManager.hpp"
#include "EventInputSystem.hpp"

using std::shared_ptr;

class MainLoop {
public:
    MainLoop(shared_ptr<SceneManager> sceneManager, shared_ptr<Logger> log);
    virtual ~MainLoop();
    void Start();
    void Stop();
    virtual void Draw();
    virtual void CheckInput();
    virtual void Update(float delta);
    virtual void UpdateDeltaTime();
protected:
    float _GetDeltaTime();
    shared_ptr<Logger> _log;
private:
    float _deltaTime;
    float _currentTime;
    mutable bool _run;
    shared_ptr<SceneManager> _sceneManager;
    shared_ptr<EventInputSystem> _currentEventInputSystem;
};
#endif // MAINLOOP_H
