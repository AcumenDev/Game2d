#include "SpriteAnimation.hpp"

SpriteAnimation::~SpriteAnimation() {
}

SpriteAnimation::SpriteAnimation(std::vector<std::shared_ptr<Texture>> textures, float animationSpeed) {
    _textures = textures;
    _animationSpeed = animationSpeed;
    _old = true;
}

SpriteAnimation::SpriteAnimation(map<string, SpriteSeries> spriteSeries) {
    _spriteSeries = spriteSeries;
    _currentSirees = _spriteSeries.begin()->first;
    _old = false;
}

void SpriteAnimation::SetSeries(string series) {
    _currentSirees = series;
}

void SpriteAnimation::Draw(FPoint point) {
    if (_old) {
        _textures.at((unsigned int) _currentSprite)->Draw(point);
    } else {
        SpriteSeries current = _spriteSeries.at(_currentSirees);
        current.get_textures().at((unsigned int) _currentSprite)->Draw(point);
    }
}

void SpriteAnimation::Step(float delta) {
    if (_old) {
        _currentSprite += _animationSpeed * delta;
        if ((unsigned int) _currentSprite > _textures.size() - 1) {
            _currentSprite = 0;
        }
    } else {
        SpriteSeries current = _spriteSeries.at(_currentSirees);
        _currentSprite += current.get_animationSpeed() * delta;

        if ((unsigned int) _currentSprite > current.get_textures().size() - 1) {
            _currentSprite = 0;
        }
    }
}