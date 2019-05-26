#pragma once

#include "Transformable2D.h"

class Shape : public Transformable2D
{
public:
	Shape();
	~Shape();
	enum Type {
		CIRCLE, LINE, POLYGON, RECTANGLE
	};
	virtual Type getType() = 0;
	virtual bool isPointInside(glm::vec2 point) = 0;
};

