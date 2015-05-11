#ifndef BOUND_H
#define BOUND_H

#include <physics/BoundPhysic.hpp>
#include "GameObjectBase.hpp"

class Bound : public virtual GameObjectBase {

public:
    Bound(std::shared_ptr<Graphic::ObjectDrawingBase> graphic, std::shared_ptr<Physic::BoundPhysic> physic) ;
    void Update(UpdateEventDto updateEventDto) override;
    shared_ptr<ObjectDrawingBase> GetDrawing() const override;


private:
    void _updateGraficPosition();
    std::shared_ptr<Graphic::ObjectDrawingBase> _graphic;
    std::shared_ptr<Physic::BoundPhysic> _physic;
};

#endif