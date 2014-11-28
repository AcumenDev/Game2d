#include "ObjectsDrawing/Font.hpp"

Font::Font(std::shared_ptr<Logger> log, SDL_Renderer* render, std::string path, int size, IPoint iPoint, int styleFont)
    :DrawingObject(log,nullptr,iPoint) {
    _log = log;
    _render = render;
    _iPoint = iPoint;
    _font=TTF_OpenFont(path.c_str(), 16);
    if(!_font) {
        _log->Error("TTF_OpenFont: "+path+" error: "+ SDL_GetError());
    }
    TTF_SetFontStyle(_font, styleFont);
}

void Font::Draw() {
    if(_texture!=nullptr) {
        _texture->Draw(_iPoint);
    }
}

void Font::SetText(std::string text) {
    SDL_Color color= {0,0,0};
    SDL_Surface *text_surface;
    if(!(text_surface=TTF_RenderUTF8_Blended(_font,text.c_str(),color))) {
        _log->Error("TTF_RenderUTF8_Solid: "+text+" error: "+ SDL_GetError());
    } else {
        SDL_Texture* texture = SDL_CreateTextureFromSurface(_render, text_surface);
        int w, h;
        SDL_QueryTexture(texture, NULL, NULL, &w, &h);
        _texture =  std::make_shared<Texture>(_render, texture, w, h);
        SDL_FreeSurface(text_surface);
    }
}

void Font::Update(float delta, std::shared_ptr<EventInputSystem> eventInputSystem, std::shared_ptr<NotificationServices> notificationServices) {

}

Font::~Font() {
    TTF_CloseFont(_font);
}
