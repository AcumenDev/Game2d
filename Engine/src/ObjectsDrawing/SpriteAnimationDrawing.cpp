#include "ObjectsDrawing/SpriteAnimationDrawing.hpp"

SpriteAnimationDrawing::SpriteAnimationDrawing(std::shared_ptr<SpriteAnimation> spriteAnimation)
     {
         _spriteAnimation = spriteAnimation;
}

void SpriteAnimationDrawing::Draw() {
    _spriteAnimation->Draw(_point);
}

void SpriteAnimationDrawing::SetPosition(FPoint const &fPoint) {
    _point = fPoint;
}

void SpriteAnimationDrawing::Step(float step)
{
    _spriteAnimation->Step(step);
}
