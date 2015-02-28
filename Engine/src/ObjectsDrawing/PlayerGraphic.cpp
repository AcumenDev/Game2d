#include "ObjectsDrawing/PlayerGraphic.hpp"

namespace Graphic {
    PlayerGraphic::PlayerGraphic(shared_ptr<SpriteAnimation> spriteAnimation, shared_ptr<Logger> log) {
        _spriteAnimation = spriteAnimation;
        _log = log;
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
}