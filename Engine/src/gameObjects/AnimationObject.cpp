#include "gameObjects/AnimationObject.hpp"

AnimationObject::AnimationObject(std::shared_ptr<SpriteAnimationDrawing> spriteAnimation){
    _spriteAnimation = spriteAnimation;
}

void AnimationObject::Update(UpdateEventDto updateEventDto) {
    _spriteAnimation->Step(updateEventDto.delta);
}

shared_ptr<ObjectDrawingBase> AnimationObject::GetDrawing() const {
    return _spriteAnimation;
}
