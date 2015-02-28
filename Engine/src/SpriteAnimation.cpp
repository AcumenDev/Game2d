#include "SpriteAnimation.hpp"

SpriteAnimation::~SpriteAnimation() {
}

SpriteAnimation::SpriteAnimation(std::vector<std::shared_ptr<Texture>> textures, float animationSpeed) {
    _textures = textures;
    _animationSpeed = animationSpeed;
    _old = true;
    _currentSprite = 0;
}

SpriteAnimation::SpriteAnimation(map<string, SpriteSeries> spriteSeries) {
    _spriteSeries = spriteSeries;
    _currentSirees = _spriteSeries.begin()->first;
    _old = false;
    _currentSprite = 0;
}

void SpriteAnimation::SetSeries(string series) {
    if (_currentSirees != series) {
        _currentSirees = series;
        _currentSprite = 0;
    }
}

unsigned int SpriteAnimation::__curSpri = -1;

void SpriteAnimation::Draw(FPoint point) {
    auto currentSprite = (unsigned int) _currentSprite;
    if (_old) {
        _textures.at(currentSprite)->Draw(point);
    } else {
        if (currentSprite != __curSpri) {
            //TODO Писать через логгер
            std::cout << "CurrentSeries: " << _currentSirees << " CurrentSprite: " << currentSprite << std::endl;
            __curSpri = currentSprite;
        }
        SpriteSeries current = _spriteSeries.at(_currentSirees);
        current.get_textures().at(currentSprite)->Draw(point);
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
        _currentSprite += (current.get_animationSpeed() * delta);

        if ((unsigned int) _currentSprite > current.get_textures().size() - 1) {
            _currentSprite = 0;
        }
    }
}