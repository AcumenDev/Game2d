#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include "Texture.hpp"
#include "SpriteAnimation.hpp"
#include "DrawingObject.hpp"
#include "Utils\IPoint.hpp"

class Player : public DrawingObject {
public:
    Player(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, IPoint iPoint);
    void Init( std::shared_ptr<SpriteAnimation> spriteAnimation);
    void SetPosition(IPoint iPoint);
    void Draw() override;
    void Update(float delta, std::shared_ptr<EventInputSystem> eventInputSystem, std::shared_ptr<NotificationServices> notificationServices) override;

    virtual ~Player();
private:
    void ToRight(float delta);
    void ToLeft(float delta);
    void Jump(int delta);

    std::shared_ptr<SpriteAnimation> _spriteAnimation;

    int _jump =0;
    bool _jumpStateUp = false;
    float _jumpSize;
    float  _jumpPosStart;
};

#endif // PLAYER_H
