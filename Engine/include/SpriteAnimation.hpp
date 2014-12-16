#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H
#include <memory>
#include <vector>
#include "Texture.hpp"
#include "Utils/IPoint.hpp"
#include "Utils/FPoint.hpp"

class SpriteAnimation {
public:
    SpriteAnimation(std::vector<std::shared_ptr<Texture>> textures, float animationSpeed);
    virtual ~SpriteAnimation();
    void Draw(IPoint iPoint);
    void Draw(FPoint iPoint);
    void Step(float delta);
protected:
private:

    float _currentSprite = 0;
    float _animationSpeed;
    std::vector<std::shared_ptr<Texture>> _textures;
};
#endif // SPRITEANIMATION_H
