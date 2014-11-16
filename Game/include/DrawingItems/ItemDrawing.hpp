#ifndef ITEMDRAWING_H
#define ITEMDRAWING_H
#include "Engine.hpp"

class ItemDrawing: public DrawingObject {
public:
    ItemDrawing(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, IPoint iPoint);
    virtual ~ItemDrawing();
    void Draw() override;
    void Update(float delta,std::shared_ptr<EventInputSystem> eventInputSystem) override;
protected:
private:
    std::shared_ptr<Texture> _texture;
    IPoint _iPoint;
    std::shared_ptr<Logger> _log;
};

#endif // ITEMDRAWING_H
