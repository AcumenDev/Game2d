#include "ObjectsDrawing/PlayerGraphic.hpp"

namespace Graphic {
    PlayerGraphic::PlayerGraphic(map<string, SpriteSeries> spriteSeries, shared_ptr<Logger> log) :
            SpriteAnimation(spriteSeries) {
        _log = log;
    }

    void PlayerGraphic::Draw() {
        SpriteAnimation::Draw(_fPoint);
    }

    PlayerGraphic::~PlayerGraphic() {

    }

    void PlayerGraphic::SetPosition(FPoint const &fPoint) {

        _fPoint = fPoint;
    }
}