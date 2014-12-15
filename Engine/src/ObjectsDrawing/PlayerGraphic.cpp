#include "ObjectsDrawing/PlayerGraphic.hpp"

namespace Graphic {
    PlayerGraphic::PlayerGraphic(shared_ptr<SpriteAnimation> spriteAnimation, shared_ptr<Logger> log) {
        _spriteAnimation = spriteAnimation;
        _log = log;
    }

    void PlayerGraphic::Draw() {
        _spriteAnimation->Draw(_iPoint);
    }

    PlayerGraphic::~PlayerGraphic() {

    }

    void PlayerGraphic::SetPosition(const IPoint &iPoint) {
        _iPoint = iPoint;
    }
}