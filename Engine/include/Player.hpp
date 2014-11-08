#ifndef PLAYER_H
#define PLAYER_H
#include "Texture.hpp"
#include "SpriteAnimation.hpp"

class Player {
public:
    Player();
    void Init(SpriteAnimation * spriteAnimation);// Texture * texture);
    void SetPosition(int x, int y);
    void Draw();
    void Update(float delta);
    void ToRight(float delta);
    void ToLeft(float delta);
    void Jump(int delta);
    virtual ~Player();
private:
    void _calculateNexSprite();
    SpriteAnimation * _spriteAnimation;
    Texture * _texture;
    int _x =0,_y=0;
    int _jump =0;
    bool _jumpStateUp = false;
    float _jumpSize;
    float  _jumpPosStart;
    float _currentSprite = 0;
};

#endif // PLAYER_H
