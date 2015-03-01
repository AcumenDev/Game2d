#ifndef SPRITEANIMATIONDRAWING_H
#define SPRITEANIMATIONDRAWING_H

#include <memory>
#include "ObjectDrawingBase.hpp"
#include "SpriteAnimation.hpp"
#include "gameObjects/GameObjectBase.hpp"

using std::shared_ptr;

class SpriteAnimationDrawing : public ObjectDrawingBase {
public:
    SpriteAnimationDrawing(std::shared_ptr<SpriteAnimation> spriteAnimation);

    void SetPosition(FPoint const &fPoint) override;

    void Step(float step);

    void Draw() override;

private:
    FPoint _point;
    std::shared_ptr<SpriteAnimation> _spriteAnimation;
};

#endif