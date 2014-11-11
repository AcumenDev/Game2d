#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H
#include <vector>
#include "Texture.hpp"
#include <memory>
class SpriteAnimation {
public:
    SpriteAnimation(std::vector<std::shared_ptr<Texture>> textures, float animationSpeed);
    virtual ~SpriteAnimation();
    void Draw(int x, int y);
    void Step(float delta);
protected:
private:

    float _currentSprite = 0;
    float _animationSpeed;
    std::vector<std::shared_ptr<Texture>> _textures;
};
#endif // SPRITEANIMATION_H
