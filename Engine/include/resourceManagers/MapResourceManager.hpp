#ifndef MAPRESOURCEMANAGER_H
#define MAPRESOURCEMANAGER_H

#include <memory>
#include <fstream>
#include "utils/logger/Logger.hpp"
#include "Utils/fileSystem/FileSystemUtils.hpp"
#include "gameObjects/GameObjectsFactory.hpp"
#include "SceneManager.hpp"
#include "BaseResourceManager.hpp"
#include <rapidjson/document.h>

using std::shared_ptr;
using std::string;
using namespace rapidjson;

struct MapItem {
    objectId id;
    FPoint point;
};

enum itemType{ single = 0, sequence };

class MapResourceManager : public BaseResourceManager<shared_ptr<SceneNode>> {
public:
    MapResourceManager(
            shared_ptr<SceneManager> sceneManager,
            shared_ptr<GameObjectsFactory> gameObjFactory,
            shared_ptr<SystemSettings> systemSettings
    );

    virtual ~MapResourceManager();

    shared_ptr<SceneNode> getResourse(string lvl) override;

private:
    string _name;
    shared_ptr<SceneManager> _sceneManager;
    shared_ptr<GameObjectsFactory> _gameObjFactory;
    shared_ptr<SystemSettings> _systemSettings;
    vector<MapItem> _mapItems;

    void _addMapItemsToSceneNode(shared_ptr<SceneNode> scene);

    vector<MapItem> _generateSequence(objectId id, FPoint xy, FPoint hw);
};

#endif