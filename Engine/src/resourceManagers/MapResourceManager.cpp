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

        objectId id = (objectId) map[i]["id"].GetInt();
        FPoint xy = FPoint(map[i]["x"].GetInt(), map[i]["y"].GetInt());

        if (map[i].HasMember("type")) {
            if (map[i]["type"].GetInt() == itemType::sequence) {
                //TODO Завести enum для типов объектов
                FPoint hw(xy.x + map[i]["w"].GetInt(), xy.y + map[i]["h"].GetInt());
                _generateSequence(id, xy, hw);
            }
        }
        else {
            MapItem params;
            params.id = id;
            params.point = xy;
            _mapItems.push_back(params);
        }
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

void MapResourceManager::_generateSequence(objectId id, FPoint xy, FPoint hw) {
    auto scriptManager = make_shared<ScriptResourceManager>(_systemSettings);
    auto boundScript = make_shared<BoundScript>(scriptManager->getResourse("Bound"));
    int boundBlockHeight = boundScript->GetHeight();
    int boundBlockWidth = boundScript->GetWidth();
    if ((int) (hw.x - xy.x) % boundBlockWidth != 0 || (int) (hw.y - xy.y) % boundBlockHeight != 0) {
        Logger::Get()->Error(_name, "Cannot fill area:" + std::to_string(xy.x) + std::to_string(xy.y) + ";" +
                                    std::to_string(hw.x) + std::to_string(hw.y) + "by objects" +
                                    std::to_string((int) id));
        return;
    }
    for (int y = xy.y; y < hw.y, y < hw.y; y += boundBlockHeight) {
        for (int x = xy.x; x < hw.x, x < hw.x; x += boundBlockWidth) {
            MapItem item;
            item.id = id;
            item.point = FPoint(x, y);
            _mapItems.push_back(item);
        }
    }
}
