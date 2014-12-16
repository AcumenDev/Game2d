#ifndef PLAYERGRAPHIC_H
#define PLAYERGRAPHIC_H
#include <memory>
#include "SpriteAnimation.hpp"
#include "ObjectDrawingBase.hpp"
#include "Logger.hpp"
#include "Utils/FPoint.hpp"

using std::shared_ptr;

namespace Graphic {
    class PlayerGraphic : public ObjectDrawingBase {
    public:
        PlayerGraphic(std::shared_ptr<SpriteAnimation> spriteAnimation, shared_ptr<Logger> log);
        void Draw() override;

        virtual void SetPosition(FPoint const &fPoint) override;
        virtual ~PlayerGraphic();
    private:
        shared_ptr<SpriteAnimation> _spriteAnimation;
        shared_ptr<Logger> _log;
        FPoint _fPoint;
    };
}

#endif