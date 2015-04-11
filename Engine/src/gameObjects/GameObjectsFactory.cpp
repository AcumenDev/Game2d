#include "gameObjects/GameObjectsFactory.hpp"

GameObjectsFactory::GameObjectsFactory(
        shared_ptr<TexturesResourceManager> texturesResourceManager,
        shared_ptr<SpriteAnimationResourceManager> spriteAnimationResourceManager,
        shared_ptr<ScriptResourceManager> scriptResourceManager,
        shared_ptr<b2World> world
) {
    _texturesResourceManager = texturesResourceManager;
    _spriteAnimationResourceManager = spriteAnimationResourceManager;
    _scriptResourceManager = scriptResourceManager;
    _world = world;
}

GameObjectsFactory::~GameObjectsFactory() {
}

shared_ptr<GameObjectBase> GameObjectsFactory::CreateGameObjectByIdAndPoint(objectId id, FPoint point) {
    switch (id) {
        case player_id:
            return createPlayer(point);
        case bound_id:
            return createBound(point);
        case animation_obj_id:
            return createAnimationObj(point);
    }
}

shared_ptr<Player> GameObjectsFactory::createPlayer(FPoint point) {
    auto playerFooTexture = _texturesResourceManager->getResourse(string("foo.png"));
    auto playerPhysic = make_shared<PlayerPhysic>(_world, playerFooTexture->getWidth(), playerFooTexture->getHeight(),
                                                  point);
    auto playerSpriteAnimation = _spriteAnimationResourceManager->getResourse(string("player.json"));
    auto playerGraphic = make_shared<PlayerGraphic>(playerSpriteAnimation);
    auto playerScript = make_shared<PlayerScript>(_scriptResourceManager->getResourse("Player"));
    return make_shared<Player>(playerPhysic, playerGraphic, playerScript);
}

shared_ptr<Bound> GameObjectsFactory::createBound(FPoint point) {

    auto boundTexture = _texturesResourceManager->getResourse(string("Bound.png"));
    auto boundGraphic = make_shared<TextureDrawing>(boundTexture);
    auto boundPhysic = make_shared<BoundPhysic>(_world, boundTexture->getWidth(), boundTexture->getHeight(), point);
    return make_shared<Bound>(boundGraphic, boundPhysic);
}

shared_ptr<AnimationObject> GameObjectsFactory::createAnimationObj(FPoint point) {

    auto fireSpriteAnimation = _spriteAnimationResourceManager->getResourse(string("fire.json"));
    auto fireAnimation = make_shared<SpriteAnimationDrawing>(fireSpriteAnimation);
    fireAnimation->SetPosition(point);
    return make_shared<AnimationObject>(fireAnimation);
}
