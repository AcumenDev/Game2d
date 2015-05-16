#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <iostream>
#include <vector>
#include <memory>
#include <Box2D/Box2D.h>
#include "SceneNode.hpp"
#include "UpdateEventDto.hpp"
#include "services/NotificationServices.hpp"
#include "scene/SceneController.hpp"
#include "Utils/debugEngine/DebugEngineBase.hpp"
#include "Utils/debugEngine/TraceEngineUtils.hpp"
#include "utils/logger/Logger.hpp"


using std::shared_ptr;
using std::vector;
using std::string;

class SceneController;

class SceneManager : public std::enable_shared_from_this<SceneManager> {
public:
    SceneManager(
            shared_ptr<b2World> physicWorld,
            shared_ptr<NotificationServices> notificationServices,
            shared_ptr<DebugEngineBase> debugEngineBase);

    virtual ~SceneManager();

    shared_ptr<SceneNode> AddChildNode(string name, bool fixedCord = false);

    void Draw();

    void Update(float delta, shared_ptr<EventInputSystem> eventInputSystem);

    void SetController(shared_ptr<SceneController> sceneController);

    bool  DeleteObjectForId(unsigned int objectId);

private:
    void _calcFps();

    shared_ptr<b2World> _physicWorld;
    vector<shared_ptr<SceneNode>> _childNodes;
    unsigned int _fps_lasttime;
    unsigned int _fps_current;
    unsigned int _fps_frames;
    shared_ptr<NotificationServices> _notificationServices;
    shared_ptr<DebugEngineBase> _debugEngineBase;
    shared_ptr<SceneController> _sceneController;
};

#endif // SCENEMANAGER_H
