#ifndef __POLYGON2D_H__
#define __POLYGON2D_H__

#include "Shape2D.h"

namespace JCS_D2DEngine
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : Polygon2D
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
	class Polygon2D 
        : public Shape2D
	{
	public:
        JCS_GameInterface::JIMat2 u;
		uint32 m_vertexCount;
        JCS_GameInterface::JIVec2f m_vertices[MaxPolyVertexCount];
        JCS_GameInterface::JIVec2f m_normals[MaxPolyVertexCount];

	public:
		Polygon2D(Graphics2D& gfx, bool autoPivot = true);
		virtual ~Polygon2D();

		virtual void initialize() override;
		virtual void update(const float32 deltaTime) override;
		virtual void draw() override;

		virtual void rotation_rotate(float32 angle = 1.0f) override;
		virtual void revolution_rotate(GameObject2D& target, float32 angle = 1.0f) override;

		void SetBox(float32 hw, float32 hh);		// Half width and half height
        void Set(JCS_GameInterface::JIVec2f* vertices, uint32 count);
        JCS_GameInterface::JIVec2f GetSupport(const JCS_GameInterface::JIVec2f& dir);		// The extreme point along a direction within a polygon

		// -- Basic Collision
		bool PolygontoPolygon(Polygon2D& obj);
		bool PolygontoCircle(Circle2D& obj);
		bool PolygontoRectangle(Rectangle2D& obj);
		bool PolygontoCapsule(Capsule2D& obj);

		// setter

		// getter

	};
}

#endif // __POLYGON2D_H__

