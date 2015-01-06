#include "ObjectsDrawing/PlayerGraphic.hpp"

namespace Graphic {
    PlayerGraphic::PlayerGraphic(shared_ptr<SpriteAnimation> spriteAnimation, shared_ptr<Logger> log) {
        _spriteAnimation = spriteAnimation;
        _log = log;
    }

    void PlayerGraphic::Draw() {
        _spriteAnimation->Draw(_fPoint);
    }

    PlayerGraphic::~PlayerGraphic() {

    }

    void PlayerGraphic::SetPosition(FPoint const &fPoint) {

        _fPoint = fPoint;
    }
}