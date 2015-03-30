#ifndef _GAME_DEBUGENGINEBASE_HPP_
#define _GAME_DEBUGENGINEBASE_HPP_

#include <UpdateEventDto.hpp>

class DebugEngineBase {
public:
    virtual void Update(UpdateEventDto updateEventDto) = 0;

    virtual void SetFps(int fps) = 0;

    virtual void SetRenderTime(int time) = 0;

    virtual void SetUpdateTime(int time) = 0;

};

#endif //_GAME_DEBUGENGINEBASE_HPP_
