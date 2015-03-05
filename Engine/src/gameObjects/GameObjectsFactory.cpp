#include "gameObjects/GameObjectsFactory.hpp"

GameObjectsFactory::GameObjectsFactory(
        shared_ptr<TexturesResourceManager> texturesResourceManager,
        shared_ptr<SpriteAnimationResourceManager> spriteAnimationResourceManager,
        shared_ptr<b2World> world
) {
    _texturesResourceManager = texturesResourceManager;
    _spriteAnimationResourceManager = spriteAnimationResourceManager;
    _world = world;
}

GameObjectsFactory::~GameObjectsFactory() {
}

shared_ptr<GameObjectBase> GameObjectsFactory::CreateGameObjectById(object_id id) {
    switch (id) {
        case player_id:
            return GameObjectsFactory::CreatePlayer();
        case bound_id:
            return GameObjectsFactory::CreateBound();
        case animation_obj_id:
            return GameObjectsFactory::CreateAnimationObj();
    }
}

shared_ptr<Player> GameObjectsFactory::CreatePlayer() {
    auto playerFooTexture = _texturesResourceManager->getResourse(string("foo.png"));
    auto playerPhysic = make_shared<PlayerPhysic>(_world, playerFooTexture->getWidth(), playerFooTexture->getHeight(), FPoint(100, 100));
    auto playerSpriteAnimation = _spriteAnimationResourceManager->getResourse(string("player.json"));
    auto playerGraphic = make_shared<PlayerGraphic>(playerSpriteAnimation);
    return make_shared<Player>(playerPhysic, playerGraphic);


}

shared_ptr<Bound> GameObjectsFactory::CreateBound() {

    auto boundTexture = _texturesResourceManager->getResourse(string("Bound.png"));
    auto boundGraphic = make_shared<TextureDrawing>(boundTexture);
    auto boundPhysic = make_shared<BoundPhysic>(_world, boundTexture->getWidth(), boundTexture->getHeight(), FPoint(0, 400));
    return make_shared<Bound>(boundGraphic, boundPhysic);
}

shared_ptr<AnimationObject> GameObjectsFactory::CreateAnimationObj() {

    auto fireSpriteAnimation = _spriteAnimationResourceManager->getResourse(string("fire.json"));
    auto fireAnimation = make_shared<SpriteAnimationDrawing>(fireSpriteAnimation);
    fireAnimation->SetPosition(FPoint(200, 200));
    return make_shared<AnimationObject>(fireAnimation);
}
