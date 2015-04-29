#include "gameObjects/GameObjectsFactory.hpp"

GameObjectsFactory::GameObjectsFactory(
        shared_ptr<TexturesResourceManager> texturesResourceManager,
        shared_ptr<SpriteAnimationResourceManager> spriteAnimationResourceManager,
        shared_ptr<ScriptResourceManager> scriptResourceManager,
        shared_ptr<b2World> world,
        shared_ptr<WeaponsManager> weaponsManager
) {
    _texturesResourceManager = texturesResourceManager;
    _spriteAnimationResourceManager = spriteAnimationResourceManager;
    _scriptResourceManager = scriptResourceManager;
    _world = world;
    _weaponsManager = weaponsManager;
}

GameObjectsFactory::~GameObjectsFactory() {
}

shared_ptr<GameObjectBase> GameObjectsFactory::CreateGameObjectByIdAndPoint(objectId id, FPoint point) {
    switch (id) {
        case player_id: {
            auto player = createPlayer(point);
            _weaponsManager->SetPlayer(player);
            return player;
        };
        case bound_id:
            return createBound(point);
        case animation_obj_id:
            return createAnimationObj(point);
        case weaponAkm:
            return CreateWeapon(id);
    }
}


shared_ptr<WeaponBase> GameObjectsFactory::CreateWeapon(objectId id) {
    switch (id) {
        case weaponAkm:
            return createWeapon();
    }
}

shared_ptr<Player> GameObjectsFactory::createPlayer(FPoint point) {
    auto playerScript = make_shared<PlayerScript>(_scriptResourceManager->getResourse("Player"));
    auto playerPhysic = make_shared<PlayerPhysic>(_world, playerScript->GetWidth(), playerScript->GetHeight(), point);
    auto playerSpriteAnimation = _spriteAnimationResourceManager->getResourse(playerScript->GetSpriteAnimationName());
    auto playerGraphic = make_shared<PlayerGraphic>(playerSpriteAnimation);

    return make_shared<Player>(playerPhysic, playerGraphic, playerScript);
}

shared_ptr<Akm> GameObjectsFactory::createWeapon() {
    auto akmScript = make_shared<AkmScript>(_scriptResourceManager->getResourse("weapons/Akm"));
    auto akmGraphic = make_shared<TextureDrawing>(_texturesResourceManager->getResourse(akmScript->getTextureName()));
    return make_shared<Akm>(akmGraphic, akmScript);
}

shared_ptr<Bound> GameObjectsFactory::createBound(FPoint point) {

    auto boundTexture = _texturesResourceManager->getResourse(string("Bound.png"));
    auto boundGraphic = make_shared<TextureDrawing>(boundTexture);
    auto boundPhysic = make_shared<BoundPhysic>(_world, boundTexture->getWidth(), boundTexture->getHeight(), point);
    return make_shared<Bound>(boundGraphic, boundPhysic);
}

shared_ptr<AnimationObject> GameObjectsFactory::createAnimationObj(FPoint point) {

    auto fireSpriteAnimation = _spriteAnimationResourceManager->getResourse(string("fire"));
    auto fireAnimation = make_shared<SpriteAnimationDrawing>(fireSpriteAnimation);
    fireAnimation->SetPosition(point);
    return make_shared<AnimationObject>(fireAnimation);
}
