#ifndef PLAYER_H
#define PLAYER_H
#include "Texture.hpp"
#include "SpriteAnimation.hpp"

class Player {
public:
    Player();
    void Init(SpriteAnimation * spriteAnimation);
    void SetPosition(int x, int y);
    void Draw();
    void Update(float delta);
    void ToRight(float delta);
    void ToLeft(float delta);
    void Jump(int delta);
    virtual ~Player();
private:
    SpriteAnimation * _spriteAnimation;
    Texture * _texture;
    int _x =0,_y=0;
    int _jump =0;
    bool _jumpStateUp = false;
    float _jumpSize;
    float  _jumpPosStart;
};

#endif // PLAYER_H
