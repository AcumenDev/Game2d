#ifndef FONT_H
#define FONT_H
#include <memory>
#include "SDL_ttf.h"
#include "utils/logger/Logger.hpp"
#include "Utils/Point.hpp"
#include "Texture.hpp"
#include "DrawingObject.hpp"
class Font : public DrawingObject {
public:
    Font(SDL_Renderer* render, std::string path, int size, FPoint point, int style = TTF_STYLE_NORMAL);
    virtual ~Font();

    void Update(UpdateEventDto updateEventDto) override;
    void Draw() override;
    void SetText(std::string text);
protected:
private:
    TTF_Font * _font;;
    SDL_Renderer* _render;
};
#endif // FONT_H
