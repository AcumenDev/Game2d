#ifndef BACKGROUNDOBJECT_HPP
#define BACKGROUNDOBJECT_HPP
#include <Utils/Point.hpp>
#include "DrawingObject.hpp"
#include "Texture.hpp"
#include "utils/logger/Logger.hpp"
#include "ObjectDrawingBase.hpp"

using namespace Utils;
namespace Graphic {
    class BackgroundObject : public ObjectDrawingBase {
    public:
        BackgroundObject(std::shared_ptr<Texture> texture, FPoint point);

        virtual ~BackgroundObject();

        void Draw() override;

        void SetPosition(FPoint const &fPoint) override;

    private:
        FPoint _point;
        shared_ptr<Texture> _texture;
    };
}

#endif // BACKGROUNDOBJECT_HPP
