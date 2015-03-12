#ifndef MAPRESOURCEMANAGER_H
#define MAPRESOURCEMANAGER_H

#include <c++/bits/shared_ptr.h>
#include "gameObjects/GameObjectsFactory.hpp"
#include "SceneManager.hpp"
#include "BaseResourceManager.hpp"

using std::shared_ptr
using std::string
using Logger

class MapResourceManager : public BaseResourceManager {
public:
    MapResourceManager(
            shared_ptr<SceneManager> sceneManager,
            shared_ptr<GameObjectsFactory> gameObjFactory,
            shared_ptr<SystemSettings> systemSettings
    );
    virtual ~MapResourceManager();
    //TODO Реализация будет возвращать scenenode с расставленными gameobject-ами
    shared_ptr<SceneNode> getResourse(string name) override;
private:
    string _name;
    shared_ptr<SceneManager> _sceneManager;
    shared_ptr<GameObjectsFactory> _gameObjFactory;
    shared_ptr<SystemSettings> _systemSettings;
};

#endif