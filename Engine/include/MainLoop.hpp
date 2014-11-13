#ifndef MAINLOOP_H
#define MAINLOOP_H
#include "SDL.h"


class MainLoop {
public:
    MainLoop();
    virtual ~MainLoop();
    void Start();
    void Stop();
    virtual void Draw() = 0;
    virtual void CheckInput() = 0;
    virtual void Update(float delta) = 0 ;
    virtual void UpdateDeltaTime();
protected:
    float _GetDeltaTime();

private:
    float _deltaTime;
    float _currentTime;
    mutable bool _run;
};

#endif // MAINLOOP_H
