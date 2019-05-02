#include "Circle.h"



Circle::Circle(float radius)
{
	m_radius = radius;
}


Circle::~Circle()
{
}

bool Circle::intersect(Circle other)
{
	float dist = MathUtils::distance(getPositionV2(), other.getPositionV2());
	return getRadius() + other.getRadius() > dist;
}

float Circle::getRadius()
{
	return getScaleV2().x * m_radius;
}
