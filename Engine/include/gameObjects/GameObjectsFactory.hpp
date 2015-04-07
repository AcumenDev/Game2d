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
using Utils::FPoint;

enum objectId {
    player_id = 0, bound_id, animation_obj_id
};

class GameObjectsFactory {
public:
    GameObjectsFactory(shared_ptr<TexturesResourceManager> texturesResourceManager,
            shared_ptr<SpriteAnimationResourceManager> spriteAnimationResourceManager,
            shared_ptr<b2World> world);

    virtual ~GameObjectsFactory();

    shared_ptr<GameObjectBase> CreateGameObjectByIdAndPoint(objectId id, FPoint point);

private:
    shared_ptr<TexturesResourceManager> _texturesResourceManager;
    shared_ptr<SpriteAnimationResourceManager> _spriteAnimationResourceManager;
    shared_ptr<b2World> _world;

    shared_ptr<Player> createPlayer(FPoint point);

    shared_ptr<Bound> createBound(FPoint point);

    shared_ptr<AnimationObject> createAnimationObj(FPoint point);
};

#endif