#ifndef GAMEOBJECTSFACTORY_H
#define GAMEOBJECTSFACTORY_H

#include "ObjectsDrawing/TextureDrawing.hpp"
#include "resourceManagers/TexturesResourceManager.hpp"
#include "resourceManagers/SpriteAnimationResourceManager.hpp"
#include "Utils/logger/Logger.hpp"
#include "Player.hpp"
#include "Bound.hpp"
#include "GameObjectBase.hpp"
#include "AnimationObject.hpp"

using std::make_shared;
using std::shared_ptr;
using std::string;

enum object_id {
    player_id = 0, bound_id, animation_obj_id
};

class GameObjectsFactory {
public:
    GameObjectsFactory(shared_ptr<TexturesResourceManager> texturesResourceManager,
            shared_ptr<SpriteAnimationResourceManager> spriteAnimationResourceManager,
            shared_ptr<b2World> world);

    virtual ~GameObjectsFactory();

    shared_ptr<GameObjectBase> CreateGameObjectById(object_id id);

private:
    shared_ptr<TexturesResourceManager> _texturesResourceManager;
    shared_ptr<SpriteAnimationResourceManager> _spriteAnimationResourceManager;
    shared_ptr<b2World> _world;

    shared_ptr<Player> CreatePlayer();

    shared_ptr<Bound> CreateBound();

    shared_ptr<AnimationObject> CreateAnimationObj();
};

#endif