#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <iostream>
#include <vector>
#include <memory>
#include <SDL.h>
#include <Box2D/Box2D.h>
#include "Utils/debugEngine/DebugEngineBase.hpp"
#include "Utils/debugEngine/TraceEngineUtils.hpp"
#include "SceneNode.hpp"
#include "utils/logger/Logger.hpp"
#include "services/NotificationServices.hpp"
#include "UpdateEventDto.hpp"

using std::shared_ptr;
using std::vector;
using std::string;

class SceneManager {
public:
    SceneManager(
            SDL_Renderer *renderer,
            shared_ptr<b2World> physicWorld,
            shared_ptr<NotificationServices> notificationServices,
            shared_ptr<DebugEngineBase> debugEngineBase);

    virtual ~SceneManager();

    shared_ptr<SceneNode> AddChildNode(string name, bool fixedCord = false);

    void Draw();

    void Update(float delta, shared_ptr<EventInputSystem> eventInputSystem);


private:
    void _calcFps();

    shared_ptr<b2World> _physicWorld;
    vector<shared_ptr<SceneNode>> _childNodes;
    SDL_Renderer *_renderer;
    unsigned int _fps_lasttime;
    unsigned int _fps_current;
    unsigned int _fps_frames;
    shared_ptr<NotificationServices> _notificationServices;
    shared_ptr<DebugEngineBase> _debugEngineBase;
};

#endif // SCENEMANAGER_H
