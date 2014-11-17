#ifndef FONT_H
#define FONT_H
#include <memory>
#include "SDL_ttf.h"
#include "Logger.hpp"
#include "Utils/IPoint.hpp"
#include "Texture.hpp"
#include "DrawingObject.hpp"
class Font : public DrawingObject {
public:
    /** Default constructor */
    Font(std::shared_ptr<Logger> log, SDL_Renderer* render, std::string path, int size, IPoint iPoint, int style = TTF_STYLE_NORMAL);
    /** Default destructor */
    virtual ~Font();

    void Update(float delta, std::shared_ptr<EventInputSystem> eventInputSystem) override;
    void Draw() override;
    void SetText(std::string text);
protected:
private:
    TTF_Font * _font;; //!< Member variable "_font;"
    std::shared_ptr<Logger> _log;
    SDL_Renderer* _render;
};
#endif // FONT_H
