#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H
#include <vector>
#include "Texture.hpp"
class SpriteAnimation
{
    public:
        SpriteAnimation(std::vector<Texture*> textures);
        virtual ~SpriteAnimation();
        void Draw(int animation, int x, int y);
    protected:
    private:
        std::vector<Texture*> _textures;
};

#endif // SPRITEANIMATION_H
