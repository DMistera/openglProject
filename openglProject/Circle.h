#pragma once

#include "MathUtils.h"
#include "Shape.h"

class Circle : Shape
{
public:
	Circle(float radius);
	~Circle();
	bool intersect(Circle other);
	float getRadius();
private:
	float m_radius;
};

