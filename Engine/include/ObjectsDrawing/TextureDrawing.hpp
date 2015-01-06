#ifndef TEXTUREDRAWING_HPP_INCLUDED
#define TEXTUREDRAWING_HPP_INCLUDED

#include <memory>
#include "ObjectDrawingBase.hpp"
#include "Texture.hpp"

using std::shared_ptr;

namespace Graphic {
    class TextureDrawing : public ObjectDrawingBase {
    public:
        TextureDrawing(shared_ptr<Texture> texture);
        void SetPosition(FPoint const &fPoint) override;
        void Draw() override;
    private:
        shared_ptr<Texture> _texture;
        FPoint _point;
    };
}

#endif