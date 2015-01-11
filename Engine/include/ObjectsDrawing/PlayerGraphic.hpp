#ifndef PLAYERGRAPHIC_H
#define PLAYERGRAPHIC_H
#include <memory>
#include "SpriteAnimation.hpp"
#include "ObjectDrawingBase.hpp"
#include "Logger.hpp"
#include "Utils/FPoint.hpp"
#include <map>

using std::shared_ptr;

namespace Graphic {
    class PlayerGraphic : public ObjectDrawingBase, public SpriteAnimation {
    public:

        PlayerGraphic(map<string, SpriteSeries> spriteSeries, shared_ptr<Logger> log);
        void Draw() override;

        virtual void SetPosition(FPoint const &fPoint) override;
        virtual ~PlayerGraphic();
    private:
        shared_ptr<Logger> _log;
        FPoint _fPoint;
    };
}

#endif