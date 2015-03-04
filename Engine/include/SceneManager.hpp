#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <iostream>
#include <vector>
#include <memory>
#include <SDL.h>
#include "SceneNode.hpp"
#include "utils/logger/Logger.hpp"
#include "Utils/SceneManagerFpsCounterBase.hpp"
#include "services/NotificationServices.hpp"
#include "Box2D/Box2D.h"

using std::shared_ptr;
using std::vector;
using std::string;

class SceneManager {
public:
    SceneManager(
            SDL_Renderer *renderer,
            shared_ptr<b2World> physicWorld,
            shared_ptr<NotificationServices> notificationServices);
    virtual ~SceneManager();
    shared_ptr<SceneNode> AddChildNode(string name);
    void Draw();
    void Update(float delta, shared_ptr<EventInputSystem> eventInputSystem);
    void SetFpsListener(shared_ptr<SceneManagerFpsCounterBase> sceneManagerFpsCounterBase);
private:
    void _calcFps();
    shared_ptr<b2World> _physicWorld;
    vector<shared_ptr<SceneNode>> _childNodes;
    SDL_Renderer *_renderer;
    shared_ptr<SceneManagerFpsCounterBase> _sceneManagerFpsCounterBase;
    unsigned int _fps_lasttime;
    unsigned int _fps_current;
    unsigned int _fps_frames;
    shared_ptr<NotificationServices> _notificationServices;
};
#endif // SCENEMANAGER_H
