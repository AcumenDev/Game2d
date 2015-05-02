#ifndef GAME_BOUNDSCRIPT_HPP
#define GAME_BOUNDSCRIPT_HPP


#include <memory>
#include "BaseScriptBinding.hpp"

using std::shared_ptr;
using std::string;

class BoundScript : public BaseScriptBinding {
public:
    BoundScript(shared_ptr<Script> script);

    ~BoundScript();

    int getWidth();

    int getHeight();

    string getTextureName();

};

#endif //GAME_BOUNDSCRIPT_HPP
