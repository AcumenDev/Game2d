#ifndef GAME_AKMSCRIPT_HPP
#define GAME_AKMSCRIPT_HPP

#include <iostream>
#include <memory>
#include "scriptBinding/Script.hpp"

using std::string;
using std::shared_ptr;
class AkmScript{
public:
    AkmScript(shared_ptr<Script> script);

    string getTextureName();

private:
    shared_ptr<Script> _script;
};

#endif //GAME_AKMSCRIPT_HPP
