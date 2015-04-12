#ifndef AKM_HPP
#define AKM_HPP


#include <memory>
#include "UpdateEventDto.hpp"
#include "gameObjects/GameObjectBase.hpp"
#include "ObjectsDrawing/ObjectDrawingBase.hpp"
#include "WeaponBase.hpp"
#include "scriptBinding/weapons/AkmScript.hpp"

using std::shared_ptr;

class Akm : public virtual WeaponBase {

public:
    Akm(shared_ptr<Graphic::ObjectDrawingBase> graphic, shared_ptr<AkmScript> script);
    void Update(UpdateEventDto updateEventDto) override;
    shared_ptr<ObjectDrawingBase> GetDrawing() const override;
    void SetPosition(FPoint point) override;
    void Shot() override;

    virtual ~Akm();
private:
  //  void _updateGraficPosition();
   shared_ptr<Graphic::ObjectDrawingBase> _graphic;
    shared_ptr<AkmScript> _script;
};

#endif