#include "SpriteAnimation.hpp"

SpriteAnimation::~SpriteAnimation() {
}

void SpriteAnimation::Draw(int x, int y) {
    _textures.at((unsigned int)_currentSprite)->render(x,y);
}

SpriteAnimation::SpriteAnimation(std::vector<std::shared_ptr<Texture>> textures, float animationSpeed) {
    _textures = textures;
    _animationSpeed = animationSpeed;
}

void SpriteAnimation::Step(float delta) {
    _currentSprite +=_animationSpeed*delta;
    if((unsigned int)_currentSprite>_textures.size()-1) {
        _currentSprite =0;
    }
}
