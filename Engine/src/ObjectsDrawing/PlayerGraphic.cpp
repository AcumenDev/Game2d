#include "ObjectsDrawing/PlayerGraphic.hpp"

namespace Graphic {
    PlayerGraphic::PlayerGraphic(shared_ptr<SpriteAnimation> spriteAnimation) {
        _spriteAnimation = spriteAnimation;
    }

    void PlayerGraphic::Draw() {
        _spriteAnimation->Draw(_fPoint);
    }

    void PlayerGraphic::Update(float delta) {
        _spriteAnimation->Step(delta);
    }

    void PlayerGraphic::SetPosition(FPoint const &fPoint) {
        _fPoint = fPoint;
    }

    void PlayerGraphic::SetSeries(string series) {
        _spriteAnimation->SetSeries(series);
    }

    void PlayerGraphic::RunOneSiries(string series) {
        _spriteAnimation->RunOneSiries(series);
    }
}