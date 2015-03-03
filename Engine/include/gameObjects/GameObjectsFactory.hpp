#ifndef GAMEOBJECTSFACTORY_H
#define GAMEOBJECTSFACTORY_H

#include "GameObjectBase.hpp"

using std::shared_ptr;
using std::string;

enum OBJECT_ID { PLAYER_ID=0, BOUND_ID, ANIMATION_OBJ_ID };

class GameObjectsFactory {
public:
    GameObjectsFactory(shared_ptr<Logger> log);
    virtual ~GameObjectsFactory();
    shared_ptr<GameObjectBase> CreateGameObjectById(OBJECT_ID id);

private:
    shared_ptr<Logger> _log;

};

#endif