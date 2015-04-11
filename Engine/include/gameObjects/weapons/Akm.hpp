#ifndef AKM_HPP
#define AKM_HPP


#include <memory>
#include "UpdateEventDto.hpp"
#include "gameObjects/GameObjectBase.hpp"
#include "ObjectsDrawing/ObjectDrawingBase.hpp"

using std::shared_ptr;

class Akm : public virtual GameObjectBase {
    Akm(shared_ptr<Graphic::ObjectDrawingBase> graphic);
    void Update(UpdateEventDto updateEventDto) override;
    shared_ptr<ObjectDrawingBase> GetDrawing() const override;

private:
  //  void _updateGraficPosition();
   shared_ptr<Graphic::ObjectDrawingBase> _graphic;
};

#endif