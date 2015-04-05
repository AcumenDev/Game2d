//
// Created by akum on 05.04.2015.
//

#include "scriptBinding/Script.hpp"


Script::Script(string path) {
    _luaState = luaL_newstate();
    luaL_dofile(_luaState, path.c_str());
    luaL_openlibs(_luaState);
    lua_pcall(_luaState, 0, 0, 0);
}


lua_State *Script::GetLuaState() {
    return _luaState;
}
