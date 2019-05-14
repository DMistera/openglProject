#pragma once

#include "Hitbox.h"
#include "Shape.h"
#include "Intersecter2D.h"

class PrismHitbox : Hitbox
{
public:
	PrismHitbox(Shape* base, float minY, float maxY);
	~PrismHitbox();
	float getMinY();
	float getMaxY();
	Shape* getBase();
	bool collide(PrismHitbox* other);
private:
	bool collideY(PrismHitbox* other);
	Shape* m_base;
	float m_minY;
	float m_maxY;
};

