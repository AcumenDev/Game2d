#include "ObjectsDrawing/PlayerOld.hpp"

PlayerOld::PlayerOld(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, FPoint point)
    :DrawingObject(log,texture,point) {
}

PlayerOld::~PlayerOld() {

}

void PlayerOld::Init(std::shared_ptr<SpriteAnimation> spriteAnimation) {
    _spriteAnimation = spriteAnimation;
}

void PlayerOld::SetPosition(FPoint point) {
    _point = point;
}

void PlayerOld::Draw() {
    _spriteAnimation->Draw(_point);
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
            _point.y-=delta;
            if(_point.y<=_jumpPosStart-_jumpSize) {
                _jumpStateUp = false;
            }
        } else {
            _point.y+=delta;
            if(_point.y>=_jumpPosStart) {
                _jump = false;
            }
        }
    }
}

void PlayerOld::ToRight(float delta) {
    _point.x+=delta;
    _spriteAnimation->Step(delta);
}

void PlayerOld::ToLeft(float delta) {
    _point.x-=delta;
    _spriteAnimation->Step(delta);
}

void PlayerOld::Jump(int delta) {
    if(_jump) {
        return;
    }
    _jumpStateUp = true;
    _jump = true;
    _jumpSize = delta;
    _jumpPosStart = _point.y;
}
