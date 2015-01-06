#include "gameObjects/Player.hpp"

Player::Player(std::shared_ptr<Logger> log, shared_ptr<PlayerPhysic> physic, shared_ptr<PlayerGraphic> graphic) {
    _log = log;
    _physic = physic;
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
        _physic->Jump(_jumpSize);
    }
    if (updateEventDto.eventInputSystem->IsLeft()) {
        _physic->ToLeft(_stepSize);
    }

    if (updateEventDto.eventInputSystem->IsRight()){
        _physic->ToRight(_stepSize);
    }

    // _log->Debug("Player", "Position  x,y "+ std::to_string(position.x)+" "+std::to_string(position.y));
}

shared_ptr<ObjectDrawingBase> Player::GetDrawing() const {
    return _graphic;
}
