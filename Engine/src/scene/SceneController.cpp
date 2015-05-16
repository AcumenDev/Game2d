#include "scene/SceneController.hpp"


void SceneController::_restartPlayer() {
    Logger::Get()->Info(_className, "Restart player");
    Logger::Get()->Info(_className, "Delete player");
    _sceneManager->DeleteObjectForId(objectId::player_id);
    Logger::Get()->Info(_className, "Create player");

    _targetNode->AttachObject(
            _gameObjFactory->CreateGameObjectByIdAndPoint(objectId::player_id, Utils::FPoint(100, 100)));

}

void SceneController::Update(shared_ptr<EventInputSystem> eventInputSystem) {
    if (eventInputSystem->IsRestartPlayer()) {
        _restartPlayer();
    }
}

void SceneController::SetSceneManager(shared_ptr<SceneManager> sceneManager) {
    _sceneManager = sceneManager;
}

void SceneController::SetTargetNode(shared_ptr<SceneNode> targetNode) {
    _targetNode = targetNode;
}

SceneController::SceneController(shared_ptr<GameObjectsFactory> gameObjFactory) {
    _gameObjFactory = gameObjFactory;
    _className = "SceneController";

}
