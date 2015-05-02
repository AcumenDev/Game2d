#ifndef GAME_BOUNDSCRIPT_HPP
#define GAME_BOUNDSCRIPT_HPP


#include <memory>
#include "BaseScriptBinding.hpp"

using std::shared_ptr;

class BoundScript : public BaseScriptBinding{
public:
    BoundScript(shared_ptr<Script> script);

    ~BoundScript();

    int GetWidth();

    int GetHeight();

private:
    shared_ptr<Script> _script;
};

#endif //GAME_BOUNDSCRIPT_HPP
