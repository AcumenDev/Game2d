#include <Utils/logger/Logger.hpp>
#include "scriptBinding/Script.hpp"

Script::Script(string path) {
    _luaState = luaL_newstate();
    auto status = luaL_dofile(_luaState, path.c_str());
    if (status != 0) {
        Logger::Get()->Error("Script", "Not loaded script file : " + path);
    }
    luaL_openlibs(_luaState);
    lua_pcall(_luaState, 0, 0, 0);
}

lua_State *Script::GetLuaState() {
    return _luaState;
}

Script::~Script() {
    lua_close(_luaState);
}
