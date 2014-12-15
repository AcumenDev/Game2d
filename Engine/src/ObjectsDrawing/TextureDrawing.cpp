#include "ObjectsDrawing/TextureDrawing.hpp"

namespace Graphic {
    TextureDrawing::TextureDrawing(shared_ptr<Texture> texture) {
        _texture = texture;
    }

    void TextureDrawing::SetPosition(const IPoint &iPoint) {
        _iPoint = iPoint;
    }
    void TextureDrawing::Draw() {
        _texture->Draw(_iPoint);
    }
}