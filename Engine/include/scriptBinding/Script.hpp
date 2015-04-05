//
// Created by akum on 05.04.2015.
//

#ifndef GAME_SCRIPT_HPP
#define GAME_SCRIPT_HPP

#include <iostream>
#include "LuaBridge.h"

extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}

using std::string;
using namespace luabridge;

class Script{
public:
    Script(string path);
    lua_State*  GetLuaState();

private:
    lua_State* _luaState;

};
#endif //GAME_SCRIPT_HPP
