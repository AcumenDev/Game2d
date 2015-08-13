#include "gameObjects/Player.hpp"

Player::Player(shared_ptr<PlayerPhysic> physic, shared_ptr<PlayerGraphic> graphic,
               shared_ptr<PlayerScript> playerScript) {
    _physic = physic;
    _physic->SetUserData(this);
    _graphic = graphic;
    _graphic->SetSeries("stay");
    _camera = Render::Get()->GetCamera();
    _playerScript = playerScript;
    _updateGraficPosition();
    _className = "Player";
    _isOnGround = false;
}

Player::~Player() {
///TODO Удялять оружее со сцены
    Logger::Get()->Debug(_className, "Delete");
}

void Player::Update(UpdateEventDto updateEventDto) {
    auto position = _physic->GetPosition();
    _graphic->SetPosition(position);
    if (_weapon) {
        _weapon->SetPosition(
                position); ////TODO непонятно кто кого должен обновлять плеер оружее или оружее само себя беря координаты плеера второе мне нравиться больше
    }
    _camera->CenterToPoint(position);
    _graphic->Update(updateEventDto.delta);
    if (updateEventDto.eventInputSystem->IsJump()) {
        if (GetIsOnGround()) {
            _graphic->RunOneSiries("jump");
            _physic->Jump(_playerScript->GetJuamSize());
            SetIsOnGround(false);
        }
        return;
    }
    if (updateEventDto.eventInputSystem->IsLeft()) {
        if (GetIsOnGround()) {
            _graphic->SetSeries("run");
            _physic->ToLeft(_playerScript->GetStepSIze());
        }
        return;
    }

    if (updateEventDto.eventInputSystem->IsRight()) {
        if (GetIsOnGround()) {
            _graphic->SetSeries("run");
            _physic->ToRight(_playerScript->GetStepSIze());
        }
        return;
    }
    if (updateEventDto.eventInputSystem->IsShot()) {
        // _graphic->RunOneSiries("sword_attack");
        _weapon->Shot();
        return;
    }
    _graphic->SetSeries("stay");
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

void Player::SetWeapon(shared_ptr<WeaponBase> weapon) {
    _weapon = weapon;
    if (_sceneNode) {
        _sceneNode->AttachObject(_weapon);
    }
}

void Player::SetSceneNone(shared_ptr<SceneNode> sceneNode) {
    _sceneNode = sceneNode;
}
