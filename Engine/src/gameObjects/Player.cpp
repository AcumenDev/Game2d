#include "gameObjects/Player.hpp"

Player::Player(std::shared_ptr<Logger> log, shared_ptr<PlayerPhysic> physic, shared_ptr<PlayerGraphic> graphic) {
    _log = log;
    _physic = physic;
    _graphic = graphic;
    
}

Player::~Player() {
    
}

void Player::Update(UpdateEventDto updateEventDto) {
    auto position = _physic->GetPosition();
    _graphic->SetPosition(position);
   _log->Debug("Player", "Position  x,y "+ std::to_string(position.x)+" "+std::to_string(position.y));
}

shared_ptr<ObjectDrawingBase> Player::GetDrawing() const {
    return _graphic;
}
