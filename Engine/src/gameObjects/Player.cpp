#include "gameObjects/Player.hpp"

Player::Player(std::shared_ptr<Logger> log, shared_ptr<PlayerPhysic> physic, shared_ptr<PlayerGraphic> graphic) {
    _log = log;
    _physic = physic;
    _physic->SetUserData(this);
    _graphic = graphic;
    _jumpSize = 300;
    _stepSize = 300;

}

Player::~Player() {

}

void Player::Update(UpdateEventDto updateEventDto) {
    auto position = _physic->GetPosition();
    _graphic->SetPosition(position);

    if (updateEventDto.eventInputSystem->IsJump()) {
        if (GetIsOnGround()) {
            _graphic->SetSeries("jump");
            _physic->Jump(_jumpSize);
            SetIsOnGround(false);
        }
        return;
    }
    if (updateEventDto.eventInputSystem->IsLeft()) {
        if (GetIsOnGround()) {
            _graphic->SetSeries("run");
            _graphic->Update(updateEventDto.delta);
            _physic->ToLeft(_stepSize);
        }
        return;
    }

    if (updateEventDto.eventInputSystem->IsRight()) {
        if (GetIsOnGround()) {
            _graphic->SetSeries("run");
            _graphic->Update(updateEventDto.delta);
            _physic->ToRight(_stepSize);
        }
        return;
    }

    // _log->Debug("Player", "Position  x,y "+ std::to_string(position.x)+" "+std::to_string(position.y));
}

shared_ptr<ObjectDrawingBase> Player::GetDrawing() const {
    return _graphic;
}


bool Player::GetIsOnGround() const {
    return _isOnGround;
}

void Player::SetIsOnGround(bool isOnGround) {
    _isOnGround = isOnGround;
    if(_isOnGround)
    {
        _graphic->SetSeries("run");
    }
}
