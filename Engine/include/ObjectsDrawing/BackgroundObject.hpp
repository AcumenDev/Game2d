#ifndef BACKGROUNDOBJECT_HPP
#define BACKGROUNDOBJECT_HPP
#include <Utils/Point.hpp>
#include "DrawingObject.hpp"
#include "Texture.hpp"
#include "Logger.hpp"
using namespace Utils;
class BackgroundObject : public DrawingObject {
public:
    BackgroundObject(std::shared_ptr<Logger> log, std::shared_ptr<Texture> texture, FPoint point);
    virtual ~BackgroundObject();
    void Draw() override;
    void Update(UpdateEventDto updateEventDto) override;
};

#endif // BACKGROUNDOBJECT_HPP
