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
	return false;
}
