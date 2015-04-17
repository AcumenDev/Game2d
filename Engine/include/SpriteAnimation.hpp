#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H

#include <memory>
#include <vector>
#include <map>
#include "Texture.hpp"
#include "Utils/Rectangle.hpp"
#include "Utils/Point.hpp"

using std::map;
using std::vector;
using std::shared_ptr;
using std::string;

class SpriteSeries {
public:
    SpriteSeries(vector<shared_ptr<Texture>> textures, double animationSpeed) {
        _textures = textures;
        _animationSpeed = animationSpeed;
    }

    float get_animationSpeed() const {
        return _animationSpeed;
    }

    vector<shared_ptr<Texture>> get_textures() {
        return _textures;
    }

private:
    float _animationSpeed;
    vector<shared_ptr<Texture>> _textures;
};

class SpriteAnimation {
public:
    SpriteAnimation(map<string, SpriteSeries> spriteSeries);

    virtual ~SpriteAnimation();

    void SetSeries(string name);

    void RunOneSiries(string name);

    void Draw(FPoint point);

    void Step(float delta);

private:
    string _className;
    double _currentSprite = 0;
    string _currentSeries;
    string _beforeSeries;
    map<string, SpriteSeries> _spriteSeries;
    bool _oneRun;
};

#endif // SPRITEANIMATION_H