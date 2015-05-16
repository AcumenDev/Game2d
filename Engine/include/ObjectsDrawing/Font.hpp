#ifndef FONT_H
#define FONT_H

#include <memory>
#include "SDL_ttf.h"
#include "utils/logger/Logger.hpp"
#include "Utils/Point.hpp"
#include "Texture.hpp"
#include "DrawingObject.hpp"
#include "ObjectDrawingBase.hpp"

namespace Graphic {
    class Font : public ObjectDrawingBase { ////TODO Отделить шрифт от его вывода
    public:
        Font(SDL_Renderer *render, std::string path, int size, FPoint point, int style = TTF_STYLE_NORMAL);

        virtual ~Font();

        void Draw() override;

        void SetPosition(FPoint const &fPoint) override;

        void SetText(std::string text,unsigned int sizeRow = 0);

    protected:
    private:
        TTF_Font *_font;;
        SDL_Renderer *_render;
        FPoint _point;
        shared_ptr<Texture> _texture;
    };
}
#endif // FONT_H
