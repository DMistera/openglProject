#pragma once

#include "MathUtils.h"
#include "Shape.h"
#include "Line2D.h"
#include "Rectangle.h"
#include <iostream>
#include <glm/glm.hpp>
#include <limits>

class Circle : public Shape
{
public:
	Circle(float radius);
	~Circle();
	bool intersects(Circle other);
	bool intersects(Line2D line, glm::vec2* p1 = nullptr, glm::vec2* p2 = nullptr);
	bool intersects(Rectangle rect);
	void resolve(Rectangle rect);
	void resolve(Line2D line);
	float distance(Line2D line);
	float getRadius();
private:
	float m_radius;

	// Inherited via Shape
	virtual Type getType() override;
};

