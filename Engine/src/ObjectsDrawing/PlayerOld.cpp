#include "ObjectsDrawing/PlayerOld.hpp"

PlayerOld::PlayerOld(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, IPoint iPoint)
    :DrawingObject(log,texture,iPoint) {
}

PlayerOld::~PlayerOld() {

}

void PlayerOld::Init(std::shared_ptr<SpriteAnimation> spriteAnimation) {
    _spriteAnimation = spriteAnimation;
}

void PlayerOld::SetPosition(IPoint iPoint) {
    _iPoint = iPoint;
}

void PlayerOld::Draw() {
    _spriteAnimation->Draw(_iPoint);
}

void PlayerOld::Update(UpdateEventDto updateEventDto) {
    auto delta = updateEventDto.delta;
    auto event = updateEventDto.eventInputSystem->event;
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

void PlayerOld::ToRight(float delta) {
    _iPoint.x+=delta;
    _spriteAnimation->Step(delta);
}

void PlayerOld::ToLeft(float delta) {
    _iPoint.x-=delta;
    _spriteAnimation->Step(delta);
}

void PlayerOld::Jump(int delta) {
    if(_jump) {
        return;
    }
    _jumpStateUp = true;
    _jump = true;
    _jumpSize = delta;
    _jumpPosStart = _iPoint.y;
}
