#ifndef GAME_AKMSCRIPT_HPP
#define GAME_AKMSCRIPT_HPP

#include <iostream>
#include <memory>
#include "scriptBinding/BaseScriptBinding.hpp"
#include "Utils/Point.hpp"
using std::string;
using std::shared_ptr;
using namespace Utils;
class AkmScript : public BaseScriptBinding {
public:
    AkmScript(shared_ptr<Script> script);

    string getTextureName() const;

    IPoint getPosition() const;
};

#endif //GAME_AKMSCRIPT_HPP
