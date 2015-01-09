#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H
#include <memory>
#include <vector>
#include <map>
#include "Texture.hpp"
#include "Utils/FRectangle.hpp"
#include "Utils/FPoint.hpp"

using std::map;
using std::vector;
using std::shared_ptr;
using std::string;

class SpriteSeries {
public:
    SpriteSeries(vector<shared_ptr<Texture>> textures, float animationSpeed) {
        _textures = textures;
        _animationSpeed = animationSpeed;
    }

    float _animationSpeed;
    vector<shared_ptr<Texture>> _textures;
};

class SpriteAnimation {
public:
    SpriteAnimation(vector<shared_ptr<Texture>> textures, float animationSpeed);
    SpriteAnimation(map<string, SpriteSeries> spriteSeries);
    virtual ~SpriteAnimation();
    void SetSeries(string series);
    void Draw(FPoint point);
    void Step(float delta);
private:
    float _currentSprite = 0;
    float _animationSpeed;
    bool _old;
    string _currentSirees;
    vector<shared_ptr<Texture>> _textures;
    map<string, SpriteSeries> _spriteSeries;
};
#endif // SPRITEANIMATION_H