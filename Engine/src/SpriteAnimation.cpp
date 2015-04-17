#include <Utils/logger/Logger.hpp>
#include "SpriteAnimation.hpp"

SpriteAnimation::~SpriteAnimation() {
}

SpriteAnimation::SpriteAnimation(map<string, SpriteSeries> spriteSeries) {
    _className = "SpriteAnimation";
    _spriteSeries = spriteSeries;
    _currentSeries = _spriteSeries.begin()->first;
    _currentSprite = 0;
    _oneRun = false;
}

void SpriteAnimation::SetSeries(string name) {
    if (_currentSeries != name && !_oneRun) {
        _currentSeries = name;
        _currentSprite = 0;
    }
}

void SpriteAnimation::Draw(FPoint point) {
    auto currentSprite = (unsigned int) _currentSprite;
    SpriteSeries current = _spriteSeries.at(_currentSeries);
    current.get_textures().at(currentSprite)->Draw(point);
}

void SpriteAnimation::Step(float delta) {
    SpriteSeries current = _spriteSeries.at(_currentSeries);
    _currentSprite += (current.get_animationSpeed() * delta);
    if ((unsigned int) _currentSprite > current.get_textures().size() - 1) {
        _currentSprite = 0;
        if (_oneRun) {
            _oneRun = false;
            _currentSeries = _beforeSeries;
        }
    }
}

void SpriteAnimation::RunOneSiries(string name) {
    _beforeSeries = _currentSeries;
    SetSeries(name);
    _oneRun = true;
}
