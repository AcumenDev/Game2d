#ifndef GAME_AKMSCRIPT_HPP
#define GAME_AKMSCRIPT_HPP

#include <iostream>
#include <memory>
#include "scriptBinding/BaseScriptBinding.hpp"

using std::string;
using std::shared_ptr;
class AkmScript : public BaseScriptBinding{
public:
    AkmScript(shared_ptr<Script> script);

    string getTextureName();

};

#endif //GAME_AKMSCRIPT_HPP
