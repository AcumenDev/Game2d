#include "gameObjects/Player.hpp"

Player::Player(std::shared_ptr<Logger> log, shared_ptr<PlayerPhysic> physic, shared_ptr<PlayerGraphic> graphic) {
    _log = log;
    _physic = physic;
    _graphic = graphic;
}

Player::~Player() {
    
}

void Player::Update(UpdateEventDto updateEventDto) {
    _graphic->SetPosition(_physic->GetPosition());
}
shared_ptr<ObjectDrawingBase> Player::GetDrawing() const {
    return _graphic;
}
