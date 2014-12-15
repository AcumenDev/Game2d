#ifndef PLAYERGRAPHIC_H
#define PLAYERGRAPHIC_H
#include <memory>
#include "SpriteAnimation.hpp"
#include "ObjectDrawingBase.hpp"
#include "Logger.hpp"
#include "Utils/IPoint.hpp"

using std::shared_ptr;

namespace Graphic {
    class PlayerGraphic : public ObjectDrawingBase {
    public:
        PlayerGraphic(std::shared_ptr<SpriteAnimation> spriteAnimation, shared_ptr<Logger> log);
        void Draw() override;

        virtual void SetPosition(const IPoint &iPoint) override;
        virtual ~PlayerGraphic();
    private:
        shared_ptr<SpriteAnimation> _spriteAnimation;
        shared_ptr<Logger> _log;
        IPoint _iPoint;
    };
}

#endif