#include "gameObjects/Player.hpp"

Player::Player(shared_ptr<PlayerPhysic> physic, shared_ptr<PlayerGraphic> graphic,
               shared_ptr<PlayerScript> playerScript) {

    _physic = physic;
    _physic->SetUserData(this);
    _graphic = graphic;
    _camera = Render::Get()->GetCamera();
    _playerScript = playerScript;
    _updateGraficPosition();
}

Player::~Player() {

}

void Player::Update(UpdateEventDto updateEventDto) {
    auto position = _physic->GetPosition();
    _graphic->SetPosition(position);
    _camera->CenterToPoint(position);

    if (updateEventDto.eventInputSystem->IsJump()) {
        if (GetIsOnGround()) {
            _graphic->SetSeries("jump");
            _physic->Jump(_playerScript->GetJuamSize());
            SetIsOnGround(false);
        }
        return;
    }
    if (updateEventDto.eventInputSystem->IsLeft()) {
        if (GetIsOnGround()) {
            _graphic->SetSeries("run");
            _graphic->Update(updateEventDto.delta);
            _physic->ToLeft(_playerScript->GetStepSIze());
        }
        return;
    }

    if (updateEventDto.eventInputSystem->IsRight()) {
        if (GetIsOnGround()) {
            _graphic->SetSeries("run");
            _graphic->Update(updateEventDto.delta);
            _physic->ToRight(_playerScript->GetStepSIze());
        }
        return;
    }

    if (updateEventDto.eventInputSystem->IsShot()) {
        _graphic->SetSeries("shot");
        return;
    }

    if (GetIsOnGround()) {
        _graphic->SetSeries("run");
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
    if (_isOnGround) {
        _graphic->SetSeries("run");
    }
}

void Player::_updateGraficPosition() {
    _graphic->SetPosition(_physic->GetPosition());
}
