#include <Utils/logger/Logger.hpp>
#include "SpriteAnimation.hpp"

SpriteAnimation::~SpriteAnimation() {
}

SpriteAnimation::SpriteAnimation(map<string, SpriteSeries> spriteSeries) {
    _className = "SpriteAnimation";
    _spriteSeries = spriteSeries;
    _currentSirees = _spriteSeries.begin()->first;
    _currentSprite = 0;
}

unsigned int SpriteAnimation::__curSpri = -1;

void SpriteAnimation::SetSeries(string series) {
    if (_currentSirees != series) {
        _currentSirees = series;
        _currentSprite = 0;
    }
}

void SpriteAnimation::Draw(FPoint point) {
    auto currentSprite = (unsigned int) _currentSprite;
    if (currentSprite != __curSpri) {
       // Logger::Get()->Debug(_className, "CurrentSeries: " + _currentSirees + " CurrentSprite: " + std::to_string(currentSprite));
        __curSpri = currentSprite;
    }
    SpriteSeries current = _spriteSeries.at(_currentSirees);
    current.get_textures().at(currentSprite)->Draw(point);
}

void SpriteAnimation::Step(float delta) {
    SpriteSeries current = _spriteSeries.at(_currentSirees);
    _currentSprite += (current.get_animationSpeed() * delta);

    if ((unsigned int) _currentSprite > current.get_textures().size() - 1) {
        _currentSprite = 0;
    }
}