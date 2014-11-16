#ifndef ITEMDRAWING_H
#define ITEMDRAWING_H
#include "Engine.hpp"

class ItemDrawing: public DrawingObject,public SelectableDrawingObject {
public:
    ItemDrawing(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, IPoint iPoint);
    virtual ~ItemDrawing();
    void Draw() override;
    void Update(float delta,std::shared_ptr<EventInputSystem> eventInputSystem) override;
protected:
private:
};

#endif // ITEMDRAWING_H
