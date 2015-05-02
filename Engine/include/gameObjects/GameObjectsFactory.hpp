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
#include "resourceManagers/ScriptResourceManager.hpp"
#include "scriptBinding/weapons/AkmScript.hpp"
#include "gameObjects/weapons/Akm.hpp"
#include "gameManagers/WeaponsManager.hpp"

using std::make_shared;
using std::shared_ptr;
using std::string;
using Utils::FPoint;

enum objectId : int {
    player_id = 0,
    bound_id,
    animation_obj_id,
    weaponAkm
};

class GameObjectsFactory {
public:
    GameObjectsFactory(shared_ptr<TexturesResourceManager> texturesResourceManager,
                       shared_ptr<SpriteAnimationResourceManager> spriteAnimationResourceManager,
                       shared_ptr<ScriptResourceManager> scriptResourceManager,
                       shared_ptr<b2World> world,
                       shared_ptr<WeaponsManager> weaponsManager);

    virtual ~GameObjectsFactory();

    shared_ptr<GameObjectBase> CreateGameObjectByIdAndPoint(objectId id, FPoint point);

    shared_ptr<WeaponBase> CreateWeapon(objectId id);

private:
    shared_ptr<TexturesResourceManager> _texturesResourceManager;
    shared_ptr<SpriteAnimationResourceManager> _spriteAnimationResourceManager;
    shared_ptr<ScriptResourceManager> _scriptResourceManager;

    shared_ptr<b2World> _world;

    shared_ptr<WeaponsManager> _weaponsManager;

    shared_ptr<Player> createPlayer(FPoint point);

    shared_ptr<Bound> createBound(FPoint point);

    shared_ptr<AnimationObject> createAnimationObj(FPoint point);

    shared_ptr<Akm> createWeapon();
};

#endif