#include "ObjectsDrawing/Player.hpp"

Player::Player(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, IPoint iPoint)
    :DrawingObject(log,texture,iPoint) {
}

Player::~Player() {

}

void Player::Init(std::shared_ptr<SpriteAnimation> spriteAnimation) {
    _spriteAnimation = spriteAnimation;
}

void Player::SetPosition(IPoint iPoint) {
    _iPoint = iPoint;
}

void Player::Draw() {
    _spriteAnimation->Draw(_iPoint);
}

void Player::Update(float delta, std::shared_ptr<EventInputSystem> eventInputSystem) {
    auto event = eventInputSystem->event;
    switch(event.type) {
    case SDL_KEYDOWN : {
        // _log->Debug("Key press: " + std::to_string(event.key.keysym.sym));
        switch(event.key.keysym.sym) {
        case SDLK_LEFT: {
            this->ToLeft(delta);
            break;
        }
        case SDLK_RIGHT: {
            this->ToRight(delta);
            break;
        }
        case SDLK_UP: {
            this->Jump(200);
            break;
        }
        }
    }
    }


    if(_jump) {
        if(_jumpStateUp) {
            _iPoint.y-=delta;
            if(_iPoint.y<=_jumpPosStart-_jumpSize) {
                _jumpStateUp = false;
            }
        } else {
            _iPoint.y+=delta;
            if(_iPoint.y>=_jumpPosStart) {
                _jump = false;
            }
        }
    }
}

void Player::ToRight(float delta) {
    _iPoint.x+=delta;
    _spriteAnimation->Step(delta);
}

void Player::ToLeft(float delta) {
    _iPoint.x-=delta;
    _spriteAnimation->Step(delta);
}

void Player::Jump(int delta) {
    if(_jump) {
        return;
    }
    _jumpStateUp = true;
    _jump = true;
    _jumpSize = delta;
    _jumpPosStart = _iPoint.y;
}
