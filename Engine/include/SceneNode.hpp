#ifndef SCENENODE_H
#define SCENENODE_H
#include <vector>
#include <memory>
#include "DrawingObject.hpp"
#include "EventInputSystem.hpp"

class SceneNode {
public:
    SceneNode(std::string name);
    virtual ~SceneNode();
    void Draw();
    void Update(UpdateEventDto updateEventDto);
    void AttachObject(std::shared_ptr<DrawingObject> drawingObject);
protected:
private:
    std::string _name;
    std::vector<std::shared_ptr<SceneNode>> _childNodes;
    std::vector<std::shared_ptr<DrawingObject>> _drawingObjects;
};
#endif // SCENENODE_H
