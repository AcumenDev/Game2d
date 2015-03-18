#include "ObjectsDrawing/Font.hpp"

namespace Graphic {
    Font::Font(SDL_Renderer *render, std::string path, int size, FPoint point, int styleFont) {
        _render = render;
        _point = point;
        _font = TTF_OpenFont(path.c_str(), 16);
        if (!_font) {
            Logger::Get()->Error("TTF_OpenFont: " + path + " error: " + SDL_GetError());
        }
        TTF_SetFontStyle(_font, styleFont);
    }

    void Font::Draw() {
        if (_texture != nullptr) {
            _texture->Draw(_point);
        }
    }

    void Font::SetText(std::string text) {
        SDL_Color color = {0, 0, 0};
        SDL_Surface *text_surface;
        if (!(text_surface = TTF_RenderUTF8_Blended(_font, text.c_str(), color))) {
            Logger::Get()->Error("TTF_RenderUTF8_Solid: " + text + " error: " + SDL_GetError());
        } else {
            SDL_Texture *texture = SDL_CreateTextureFromSurface(_render, text_surface);
            int w, h;
            SDL_QueryTexture(texture, NULL, NULL, &w, &h);
            _texture = std::make_shared<Texture>(_render, texture, w, h);
            SDL_FreeSurface(text_surface);
        }
    }


    Font::~Font() {
        TTF_CloseFont(_font);
    }

    void Font::SetPosition(FPoint const &fPoint) {
        _point = fPoint;
    }
}