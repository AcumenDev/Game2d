#include "resourceManagers/MapResourceManager.hpp"

MapResourceManager::MapResourceManager(
        shared_ptr<SceneManager> sceneManager,
        shared_ptr<GameObjectsFactory> gameObjFactory,
        shared_ptr<SystemSettings> systemSettings) :
        _name("MapResourceManager"),
        _sceneManager(sceneManager),
        _gameObjFactory(gameObjFactory),
        _systemSettings(systemSettings) {
}

MapResourceManager::~MapResourceManager() {
}

shared_ptr<SceneNode> MapResourceManager::getResourse(string name) {
    auto path = FileSystem::Path::Combine(_systemSettings->get_resFolder(), name);
    Logger::Get()->Debug(_name, "Loading map from: " + path);
    std::ifstream map(path.c_str());
    if (!map.is_open()) {
        Logger::Get()->Error(_name, "Couldn't load map file : " + path);
        return nullptr;
    }
    auto sceneNode = _sceneManager->AddChildNode("MainNode");
    GetParamsFromFile(map);
    AddObjectsToSceneNode(sceneNode);
    return sceneNode;
}

void MapResourceManager::GetParamsFromFile(std::ifstream &map) {
    while (!map.eof()) {
        GameObjParams params;
        string c;
        getline(map, c, ',');
        params.id = stoi(c);
        getline(map, c, ',');
        params.x = stoi(c);
        getline(map, c, ',');
        params.y = stoi(c);
        _parmsFromFile.push_back(params);
    }
}

void MapResourceManager::AddObjectsToSceneNode(shared_ptr<SceneNode> scene) {
    for (const auto &item : _parmsFromFile) {
        scene->AttachObject(
                _gameObjFactory->CreateGameObjectByIdAndPoint((object_id) item.id, FPoint(item.x, item.y)));
    }
}
