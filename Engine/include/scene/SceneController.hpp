#ifndef GAME_SCENECONTROLLER_H
#define GAME_SCENECONTROLLER_H

#include <memory>
#include "EventInputSystem.hpp"
#include "SceneManager.hpp"
#include "SceneNode.hpp"
#include "gameObjects/GameObjectsFactory.hpp"

using std::shared_ptr;

class SceneManager;

class SceneController {
public:
    SceneController( shared_ptr<GameObjectsFactory> gameObjFactory);

    void SetSceneManager(shared_ptr<SceneManager> sceneManager);

    void Update(shared_ptr<EventInputSystem> eventInputSystem);

    void SetTargetNode(shared_ptr<SceneNode> targetNode);

private:
    void _restartPlayer();

    shared_ptr<SceneManager> _sceneManager;
    string _className;
    shared_ptr<SceneNode> _targetNode;
    shared_ptr<GameObjectsFactory> _gameObjFactory;
};

#endif //GAME_SCENECONTROLLER_H