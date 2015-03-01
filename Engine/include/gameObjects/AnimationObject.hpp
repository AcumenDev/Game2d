#ifndef ANIMATIONOBJECT_H
#define ANIMATIONOBJECT_H

#include <memory>
#include "GameObjectBase.hpp"
#include "ObjectsDrawing/SpriteAnimationDrawing.hpp"

class AnimationObject : public virtual GameObjectBase {

public:
    AnimationObject(std::shared_ptr<SpriteAnimationDrawing> spriteAnimation);

    virtual void Update(UpdateEventDto updateEventDto) override;

    virtual shared_ptr<ObjectDrawingBase> GetDrawing() const override;

private:
    std::shared_ptr<SpriteAnimationDrawing> _spriteAnimation;
};
#endif

