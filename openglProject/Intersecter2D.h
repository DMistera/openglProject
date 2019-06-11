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
	static void resolve(Shape* nonSolid, Shape* solid, glm::vec2 shift);
};

