#include <Utils/FPoint.hpp>
#include "ObjectsDrawing/TextureDrawing.hpp"

namespace Graphic {
    TextureDrawing::TextureDrawing(shared_ptr<Texture> texture) {
        _texture = texture;
    }

    void TextureDrawing::SetPosition(FPoint const &fPoint) {
        _iPoint = fPoint;
    }
    void TextureDrawing::Draw() {
        _texture->Draw(_iPoint);
    }
}