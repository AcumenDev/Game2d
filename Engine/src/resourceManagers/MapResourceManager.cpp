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

shared_ptr<SceneNode> MapResourceManager::getResourse(string lvl) {
    auto path = _systemSettings->get_mapPathForLvl(lvl);
    Logger::Get()->Debug(_name, "Loading map from: " + path);
    std::ifstream mapFile(path.c_str());
    if (!mapFile.is_open()) {
        Logger::Get()->Error(_name, "Couldn't load map file : " + path);
        return nullptr;
    }
    _getMapItemsFromFile(mapFile);
    mapFile.close();
    auto sceneNode = _sceneManager->AddChildNode("MainNode");
    _addMapItemsToSceneNode(sceneNode);
    return sceneNode;
}

void MapResourceManager::_getMapItemsFromFile(std::ifstream &mapFile) {
    while (!mapFile.eof()) {
        MapItem params;
        string c;
        getline(mapFile, c, ',');
        params.id = (objectId) stoi(c);
        getline(mapFile, c, ',');
        int x = stoi(c);
        getline(mapFile, c, ',');
        int y = stoi(c);
        params.point = FPoint(x, y);
        _mapItems.push_back(params);
    }
}

void MapResourceManager::_addMapItemsToSceneNode(shared_ptr<SceneNode> scene) {
    for (const auto &item : _mapItems) {
        scene->AttachObject(
                _gameObjFactory->CreateGameObjectByIdAndPoint(item.id, item.point));
    }
}
