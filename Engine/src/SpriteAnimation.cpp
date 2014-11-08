#include "SpriteAnimation.hpp"

SpriteAnimation::~SpriteAnimation() {
}

void SpriteAnimation::Draw(int animation, int x, int y) {
    _textures.at(animation)->render(x,y);
}

SpriteAnimation::SpriteAnimation(std::vector<Texture*> textures) {
    _textures = textures;
}
