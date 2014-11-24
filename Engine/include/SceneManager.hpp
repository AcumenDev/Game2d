#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <iostream>
#include <vector>
#include <memory>
#include <SDL.h>
#include "SceneNode.hpp"
#include "Logger.hpp"
#include "Utils/SceneManagerFpsCounterBase.hpp"
#include "services/NotificationServices.hpp"
class SceneManager {
public:
    SceneManager(std::shared_ptr<Logger> log, SDL_Renderer* renderer, std::shared_ptr<NotificationServices<std::string>> notificationServices);
    virtual ~SceneManager();
    std::shared_ptr<SceneNode> AddChildNode(std::string name);
    void Draw();
    void Update(float delta,std::shared_ptr<EventInputSystem> eventInputSystem);
    void SetFpsListener(std::shared_ptr<SceneManagerFpsCounterBase> sceneManagerFpsCounterBase);
protected:
private:
    void _calcFps();
    std::vector<std::shared_ptr<SceneNode>> _childNodes;
    std::shared_ptr<Logger> _log;
    SDL_Renderer* _renderer;
    std::shared_ptr<SceneManagerFpsCounterBase> _sceneManagerFpsCounterBase;
    unsigned int _fps_lasttime;
    unsigned int _fps_current;
    unsigned int _fps_frames;
    std::shared_ptr<NotificationServices<std::string>> _notificationServices;
};
#endif // SCENEMANAGER_H
