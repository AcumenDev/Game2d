#ifndef PLAYERGRAPHIC_H
#define PLAYERGRAPHIC_H

#include <memory>
#include "SpriteAnimation.hpp"
#include "ObjectDrawingBase.hpp"
#include "utils/logger/Logger.hpp"
#include "Utils/Point.hpp"
#include <map>

using std::shared_ptr;

namespace Graphic {
    class PlayerGraphic : public ObjectDrawingBase {
    public:

        PlayerGraphic(shared_ptr<SpriteAnimation> spriteAnimation);

        void Draw() override;

        virtual void SetPosition(FPoint const &fPoint) override;

        void Update(float delta) ;
        void SetSeries(string series);

        virtual ~PlayerGraphic() {
        }

    private:
        FPoint _fPoint;
        shared_ptr<SpriteAnimation> _spriteAnimation;
    };
}

#endif