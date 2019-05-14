#pragma once

#include "Shape.h"
#include "Circle.h"
#include "Line2D.h"

class Intersecter2D
{
public:
	Intersecter2D();
	~Intersecter2D();
	static bool intersect(Shape* a, Shape* b);
};

