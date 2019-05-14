#pragma once

#include "Transformable.h"

class Shape : public Transformable
{
public:
	Shape();
	~Shape();
	enum Type {
		CIRCLE, LINE, POLYGON, RECTANGLE
	};
	virtual Type getType() = 0;
};

