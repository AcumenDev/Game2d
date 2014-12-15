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
        void SetPosition(const IPoint &iPoint) override;
        void Draw() override;
    private:
        shared_ptr<Texture> _texture;
        IPoint _iPoint;
    };
}

#endif