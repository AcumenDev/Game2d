#include <vector>
#include "Box2D/Box2D.h"
#include <SDL_render.h>
namespace Graphic {
    class PhysicDraw : public b2Draw {

    public:
        PhysicDraw(float coff);
        void DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) override;
        void DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) override;
        void DrawCircle(const b2Vec2 &center, float32 radius, const b2Color &color) override;
        void DrawSolidCircle(const b2Vec2 &center, float32 radius, const b2Vec2 &axis, const b2Color &color) override;
        void DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color) override;
        void DrawTransform(const b2Transform &xf) override;

    private:
        float _coff;
        void SetColor(b2Color const &color);
        float ToScrean(float i);
        void DrawPolygons(b2Vec2 const *vertices, int32 vertexCount, b2Color const &color);
    };

}