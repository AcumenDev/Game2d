#include "resourceManagers/MapResourceManager.hpp"

MapResourceManager::MapResourceManager(
        shared_ptr<SceneManager> sceneManager,
        shared_ptr<GameObjectsFactory> gameObjFactory,
        shared_ptr<SystemSettings> systemSettings) :
        _name( "MapResourceManager"),
        _sceneManager(sceneManager),
        _gameObjFactory(gameObjFactory),
        _systemSettings(systemSettings) {
    }

MapResourceManager::~MapResourceManager() {
}

shared_ptr<SceneNode> MapResourceManager::getResourse(string name) {
        auto path = FileSystem::Path::Combine(_systemSettings->get_resFolder(), name);
        Logger::Get()->Debug(_name,"Loading map from: "+ path);
        std::ifstream map(path.c_str());
        if (!map.is_open()) {
                Logger::Get()->Error(_name, "Couldn't load map file : " + path);
                return nullptr;
        }
        auto sceneNode = _sceneManager->AddChildNode("MainNode");

        //TODO тут будет код чтения данных карты из бинарного файла(???) и создание на их основе gameobject-ов + добавление их в sceneNode

        return sceneNode;
}

