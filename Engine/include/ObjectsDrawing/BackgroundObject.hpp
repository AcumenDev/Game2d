#ifndef BACKGROUNDOBJECT_HPP
#define BACKGROUNDOBJECT_HPP
#include "DrawingObject.hpp"
#include "Texture.hpp"
#include "Utils\IPoint.hpp"
class BackgroundObject : public DrawingObject {
public:
    BackgroundObject(std::shared_ptr<Texture> texture, IPoint iPoint);
    virtual ~BackgroundObject();
    void Draw() override;
    void Update(float delta,std::shared_ptr<EventInputSystem> eventInputSystem) override;
protected:
private:
    std::shared_ptr<Texture> _texture;
    IPoint _iPoint;
};

#endif // BACKGROUNDOBJECT_HPP
