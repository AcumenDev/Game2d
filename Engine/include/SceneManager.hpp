#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <iostream>
#include <vector>
#include <memory>
#include <SDL.h>
#include "SceneNode.hpp"
#include "Logger.hpp"
class SceneManager {
public:
    SceneManager(std::shared_ptr<Logger> log, SDL_Renderer* renderer);
    virtual ~SceneManager();
    std::shared_ptr<SceneNode> AddChildNode(std::string name);
    void Draw();
    void Update(float delta,std::shared_ptr<EventInputSystem> eventInputSystem);
protected:
private:
    std::vector<std::shared_ptr<SceneNode>> _childNodes;
    std::shared_ptr<Logger> _log;
    SDL_Renderer* _renderer;
};

#endif // SCENEMANAGER_H
