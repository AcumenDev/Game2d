#ifndef PLAYEROLD_H
#define PLAYEROLD_H
#include <memory>

#include "SpriteAnimation.hpp"
#include "Texture.hpp"
#include "DrawingObject.hpp"
#include "Utils/IPoint.hpp"

class PlayerOld : public DrawingObject {
public:
    PlayerOld(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, IPoint iPoint);
    void Init(std::shared_ptr<SpriteAnimation> spriteAnimation);
    void SetPosition(IPoint iPoint);
    void Draw() override;
    void Update(UpdateEventDto updateEventDto) override;
    virtual ~PlayerOld();
private:
    void ToRight(float delta);
    void ToLeft(float delta);
    void Jump(int delta);
    std::shared_ptr<SpriteAnimation> _spriteAnimation;
    int _jump =0;
    bool _jumpStateUp = false;
    float _jumpSize;
    float _jumpPosStart;
};

#endif // PLAYEROLD_H
