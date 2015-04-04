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

struct GameObjParams {
    int id, x, y;
};

class MapResourceManager : public BaseResourceManager<shared_ptr<SceneNode>> {
public:
    MapResourceManager(
            shared_ptr<SceneManager> sceneManager,
            shared_ptr<GameObjectsFactory> gameObjFactory,
            shared_ptr<SystemSettings> systemSettings
    );

    virtual ~MapResourceManager();

    shared_ptr<SceneNode> getResourse(string name) override;

private:
    string _name;
    shared_ptr<SceneManager> _sceneManager;
    shared_ptr<GameObjectsFactory> _gameObjFactory;
    shared_ptr<SystemSettings> _systemSettings;
    vector<GameObjParams> _parmsFromFile;

    void AddObjectsToSceneNode(shared_ptr<SceneNode> scene);

    void GetParamsFromFile(std::ifstream &map);
};

#endif