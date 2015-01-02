#include "ObjectsDrawing/Utils/PhysicDraw.hpp"
#include <iostream>
namespace Graphic {
    void PhysicDraw::SetColor(b2Color const &color) {
        SDL_SetRenderDrawColor(_renderer, (int) color.r * 255, (int) color.g * 255, (int) color.b * 255, (int) color.a * 255);
    }

    float PhysicDraw::ToScrean(float i){
        return i * _coff;
    }

    void PhysicDraw::DrawPolygons(b2Vec2 const *vertices, int32 vertexCount, b2Color const &color) {
        SetColor(color);

        std::vector<SDL_Point> points;

        for (int i = 0; i < vertexCount; i++) {
            b2Vec2 vec2 = vertices[i];
            SDL_Point point;
            point.x = ToScrean(vec2.x);
            point.y = ToScrean(vec2.y);

            points.push_back(point);
        }
        points.push_back(points.front());

      //  for (int j = 0; j <points.size(); ++j) {

       //     std::cout<<"i: "<<j<<" x :"<<points[j].x<<" y :"<<points[j].y<<std::endl;
       // }

        SDL_RenderDrawLines(_renderer, points.data(), points.size());
    }

    PhysicDraw::PhysicDraw(SDL_Renderer *renderer, float coff) {
        _renderer = renderer;
        _coff = coff;
        SetFlags( b2Draw::e_centerOfMassBit | b2Draw::e_shapeBit);// | b2Draw::e_aabbBit); // );//
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
      //  std::cout<<"Position : "<<" x :"<<ToScrean(xf.p.x)<<" y :"<<ToScrean(xf.p.y)<<std::endl;
        b2Vec2 p1 = xf.p, p2;
        const float32 k_axisScale = 0.4f;
        SetColor({1.0f, 0.0f, 0.0f});

        std::vector<SDL_Point> points;
            SDL_Point point;
            point.x = ToScrean(p1.x);
            point.y =ToScrean(p1.y);

            points.push_back(point);
        p2 = p1 + k_axisScale * xf.q.GetXAxis();

        SDL_Point point2;
        point2.x = ToScrean(p2.x);
        point2.y = ToScrean(p2.y);

        points.push_back(point2);

        SDL_RenderDrawLines(_renderer, points.data(), 2);
        SetColor({0.0f, 1.0f, 0.0f});

        std::vector<SDL_Point> points2;
        SDL_Point point3;
        point3.x = ToScrean(p1.x);
        point3.y = ToScrean(p1.y);

        points2.push_back(point3);
        p2 = p1 + k_axisScale * xf.q.GetYAxis();
        SDL_Point point4;
        point4.x = ToScrean(p2.x);
        point4.y =ToScrean(p2.y);

        points2.push_back(point4);
        SDL_RenderDrawLines(_renderer, points2.data(), 2);
    }
}