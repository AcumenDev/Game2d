#ifndef ITEMDRAWING_H
#define ITEMDRAWING_H


#include <DrawingObject.hpp>
#include <SelectableDrawingObject.hpp>

class ItemDrawing : public DrawingObject, public SelectableDrawingObject {
public:
    ItemDrawing(std::shared_ptr<Texture> texture, FPoint point, std::string name);

    virtual ~ItemDrawing();

    void Draw() override;

    void Update(UpdateEventDto updateEventDto) override;

protected:
private:
    bool _notyfy;
    std::string _name;
};

#endif // ITEMDRAWING_H
