#include <c++/bits/shared_ptr.h>
#include <gameObjects/AnimationObject.hpp>
#include <gameObjects/GameObjectsFactory.hpp>
#include "GameObjectsFactory.hpp"

GameObjectsFactory::GameObjectsFactory(shared_ptr < Logger > log) : _log(log) {
}

GameObjectsFactory::~GameObjectsFactory() {
}

shared_ptr<GameObjectBase> GameObjectsFactory::GetGameObjectById(OBJECT_ID id) {
    switch (id){
        case PLAYER_ID:
            return shared_ptr<Player>;
        case BOUND_ID:
            return shared_ptr<Bound>;
        case ANIMATION_OBJ_ID:
            return shared_ptr<AnimationObject>;
    }
}