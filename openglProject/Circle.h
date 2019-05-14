#pragma once

#include "MathUtils.h"
#include "Shape.h"
#include "Line2D.h"
#include "Rectangle.h"
#include <iostream>

class Circle : public Shape
{
public:
	Circle(float radius);
	~Circle();
	bool intersects(Circle other);
	bool intersects(Line2D line);
	bool intersects(Rectangle rect);
	float getRadius();
private:
	float m_radius;

	// Inherited via Shape
	virtual Type getType() override;
};

