#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H
#include <vector>
#include "Texture.hpp"
class SpriteAnimation {
public:
    SpriteAnimation(std::vector<Texture*> textures, float animationSpeed);
    virtual ~SpriteAnimation();
    void Draw(int x, int y);
    void Step(float delta);
protected:
private:

    float _currentSprite = 0;
    float _animationSpeed;
    std::vector<Texture*> _textures;
};
#endif // SPRITEANIMATION_H
