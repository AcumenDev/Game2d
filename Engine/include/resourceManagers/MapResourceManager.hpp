#ifndef MAPRESOURCEMANAGER_H
#define MAPRESOURCEMANAGER_H

#include <memory>
#include <fstream>
#include "utils/logger/Logger.hpp"
#include "Utils/fileSystem/FileSystemUtils.hpp"
#include "gameObjects/GameObjectsFactory.hpp"
#include "SceneManager.hpp"
#include "BaseResourceManager.hpp"

using std::shared_ptr;
using std::string;

struct MapItem {
    objectId id;
    FPoint point;
};

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

    void _getMapItemsFromFile(std::ifstream &mapFile);
};

#endif