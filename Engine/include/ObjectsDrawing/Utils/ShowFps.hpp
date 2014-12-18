#ifndef SHOWFPS_H
#define SHOWFPS_H
#include "ObjectsDrawing/Font.hpp"
#include "Utils/SceneManagerFpsCounterBase.hpp"
class ShowFps: public Font, public SceneManagerFpsCounterBase  {
public:
    /** Default constructor */
    ShowFps(std::shared_ptr<Logger> log, SDL_Renderer* render, std::string path, int size, FPoint point,int style =  TTF_STYLE_BOLD);
    /** Default destructor */
    virtual ~ShowFps();
    void Update(int fps) override;
protected:
private:
};
#endif // SHOWFPS_H
