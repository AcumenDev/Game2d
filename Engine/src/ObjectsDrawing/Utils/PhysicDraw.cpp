#include "ObjectsDrawing/Utils/PhysicDraw.hpp"
#include <iostream>
namespace Graphic {
    void PhysicDraw::SetColor(b2Color const &color) {
        SDL_SetRenderDrawColor(_renderer, (int) color.r * 255, (int) color.g * 255, (int) color.b * 255, (int) color.a * 255);
    }

    void PhysicDraw::DrawPolygons(b2Vec2 const *vertices, int32 vertexCount, b2Color const &color) {
        SetColor(color);

        std::vector<SDL_Point> points;
        float StP = 100.0f;
        for (int i = 0; i < vertexCount; i++) {
            b2Vec2 vert = vertices[i];
            SDL_Point point;
            point.x = vert.x * StP;
            point.y = vert.y * StP;

            points.push_back(point);

        }

//points.push_back(points.front());
        for (int j = 0; j <points.size(); ++j) {

            std::cout<<"i: "<<j<<" x :"<<points[j].x<<" y :"<<points[j].y<<std::endl;
        }


        SDL_RenderDrawLines(_renderer, points.data(), vertexCount);
    }

    PhysicDraw::PhysicDraw(SDL_Renderer *renderer) {
        _renderer = renderer;
        SetFlags(b2Draw::e_shapeBit);//| b2Draw::e_aabbBit); // );//
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