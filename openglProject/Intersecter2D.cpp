#include "Intersecter2D.h"



Intersecter2D::Intersecter2D()
{
}


Intersecter2D::~Intersecter2D()
{
}

bool Intersecter2D::intersect(Shape* a, Shape* b)
{
	if (a->getType() == Shape::CIRCLE) {
		Circle* circle = dynamic_cast<Circle*>(a);
		if (b->getType() == Shape::CIRCLE) {
			return circle->intersects(*dynamic_cast<Circle*>(b));
		}
		else if(b->getType() == Shape::LINE) {
			return circle->intersects(*dynamic_cast<Line2D*>(b));
		}
		else if(b->getType() == Shape::RECTANGLE) {
			return circle->intersects(*dynamic_cast<Rectangle*>(b));;
		}
		else {
			throw "Not supported shape";
		}
	}
	else if (a->getType() == Shape::RECTANGLE) {
		Rectangle* rect = dynamic_cast<Rectangle*>(a);
		if (b->getType() == Shape::CIRCLE) {
			return dynamic_cast<Circle*>(b)->intersects(*rect);
		}
		else if (b->getType() == Shape::RECTANGLE) {
			return rect->intersects(*dynamic_cast<Rectangle*>(b));;
		}
		else {
			throw "Not supported shape";
		}
	}
	return false;
}

void Intersecter2D::resolve(Shape * nonSolid, Shape * solid, glm::vec2 shift)
{
	if (nonSolid->getType() == Shape::CIRCLE) {
		Circle* circle = dynamic_cast<Circle*>(nonSolid);
		if (solid->getType() == Shape::CIRCLE) {
			throw "Not supported shape";
		}
		else if (solid->getType() == Shape::LINE) {
			circle->resolve(*dynamic_cast<Line2D*>(solid));
		}
		else if (solid->getType() == Shape::RECTANGLE) {
			circle->resolve(*dynamic_cast<Rectangle*>(solid), shift);
		}
		else {
			throw "Not supported shape";
		}
	}
}
