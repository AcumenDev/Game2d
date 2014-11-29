#ifndef SCENENODE_H
#define SCENENODE_H
#include <vector>
#include <memory>
#include "DrawingObject.hpp"
#include "EventInputSystem.hpp"
#include "ObjectBase.hpp"

class SceneNode{
public:
    SceneNode(std::shared_ptr<Logger> log, std::string nameNode);
    virtual ~SceneNode();
    void Draw();
    void Update(UpdateEventDto updateEventDto);
    void AttachObject(std::shared_ptr<DrawingObject> drawingObject);
protected:
private:
    std::string _nameNode;
    std::shared_ptr<Logger> _log;
    std::vector<std::shared_ptr<SceneNode>> _childNodes;
    std::vector<std::shared_ptr<DrawingObject>> _drawingObjects;
};
#endif // SCENENODE_H
