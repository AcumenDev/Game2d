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

    string jsonString = string((std::istreambuf_iterator<char>(mapFile)),
                               (std::istreambuf_iterator<char>()));

    Document doc;
    doc.Parse<ParseFlag::kParseDefaultFlags>(jsonString.c_str());
    const Value &map = doc["map"];

    for (SizeType i = 0; i < map.Size(); i++) {
        MapItem params;
        objectId id = (objectId) map[i]["id"].GetInt();
        FPoint xy = FPoint(map[i]["x"].GetInt(), map[i]["y"].GetInt());
        if (map[i].HasMember("type")) {
            FPoint hw(xy.x + map[i]["w"].GetInt(), xy.y + map[i]["h"].GetInt());
            _generateSequence(id, xy, hw);
        }
        params.id = id;
        params.point = xy;
        _mapItems.push_back(params);
    }

    mapFile.close();
    auto sceneNode = _sceneManager->AddChildNode("MainNode");
    _addMapItemsToSceneNode(sceneNode);
    return sceneNode;
}

void MapResourceManager::_addMapItemsToSceneNode(shared_ptr<SceneNode> scene) {
    for (const auto &item : _mapItems) {
        scene->AttachObject(
                _gameObjFactory->CreateGameObjectByIdAndPoint(item.id, item.point));
    }
}

vector<MapItem> MapResourceManager::_generateSequence(objectId id, FPoint xy, FPoint hw) {
    std::vector<MapItem> result;
// TODO Здесь будет заполнение необходимой области объектами
    // TODO размер объекта будет браться из lua-скрипта нужно это сделать на подобии playerScript
    return result;
}
