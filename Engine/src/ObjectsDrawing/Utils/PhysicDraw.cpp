#include <vector>
#include <Box2D/Common/b2Math.h>
#include <SDL_rect.h>
#include <SDL_render.h>
#include "ObjectsDrawing/Utils/PhysicDraw.hpp"

namespace Graphic {
    void PhysicDraw::SetColor(b2Color const &color) {
        SDL_SetRenderDrawColor(_renderer, (int) color.r * 255, (int) color.g * 255, (int) color.b * 255, (int) color.a * 255);
    }

    void PhysicDraw::DrawPolygons(b2Vec2 const *vertices, int32 vertexCount, b2Color const &color) {
        SetColor(color);

        std::vector<SDL_Point> points;

        for (int i = 0; i <= vertexCount; i++) {
            b2Vec2 vert = vertices[i];
            SDL_Point point;
            point.x = vert.x;
            point.y = vert.y;

            points.push_back(point);
        }

        SDL_RenderDrawLines(_renderer, points.data(), vertexCount);
    }

    PhysicDraw::PhysicDraw(SDL_Renderer *renderer) {
        _renderer = renderer;
        SetFlags(b2Draw::e_shapeBit);
    }

    void PhysicDraw::DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) {
        DrawPolygons(vertices, vertexCount, color);
    }

    void PhysicDraw::DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) {
        DrawPolygons(vertices, vertexCount, color);
    }
    void PhysicDraw::DrawCircle(const b2Vec2 &center, float32 radius, const b2Color &color) {
        SetColor(color);
    }
    void PhysicDraw::DrawSolidCircle(const b2Vec2 &center, float32 radius, const b2Vec2 &axis, const b2Color &color) {
        SetColor(color);
    }
    void PhysicDraw::DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color) {
        SetColor(color);
    }
    void PhysicDraw::DrawTransform(const b2Transform &xf) {
    }
}