#ifndef MAINLOOP_H
#define MAINLOOP_H
#include "SDL.h"
#include "SceneManager.hpp"
#include "EventInputSystem.hpp"
class MainLoop {
public:
    MainLoop(std::shared_ptr<SceneManager> sceneManager, std::shared_ptr<Logger> log);
    virtual ~MainLoop() {};
    void Start();
    void Stop();
    virtual void Draw();
    virtual void CheckInput();
    virtual void Update(float delta) ;
    virtual void UpdateDeltaTime();
protected:
    float _GetDeltaTime();
    std::shared_ptr<Logger> _log;
private:
    float _deltaTime;
    float _currentTime;
    mutable bool _run;
    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<EventInputSystem> _currentEventInputSystem;
};
#endif // MAINLOOP_H
