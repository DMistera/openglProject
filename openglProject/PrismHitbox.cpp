#include "PrismHitbox.h"



PrismHitbox::PrismHitbox(Shape* base, float minY, float maxY)
{
	m_base = base;
	m_minY = minY;
	m_maxY = maxY;
}


PrismHitbox::~PrismHitbox()
{
}

float PrismHitbox::getMinY()
{
	return m_minY;
}

float PrismHitbox::getMaxY()
{
	return m_maxY;
}

Shape * PrismHitbox::getBase()
{
	return m_base;
}

bool PrismHitbox::collide(PrismHitbox * other)
{
	if (collideY(other)) {
		if (Intersecter2D::intersect(m_base, other->getBase())) {
			return true;
		}
	}
	return false;
}

bool PrismHitbox::collideY(PrismHitbox * other)
{
	float o_minY = other->getMinY();
	float o_maxY = other->getMaxY();
	if (m_minY < o_minY) {
		return m_maxY > o_minY;
	}
	else {
		return o_maxY > m_minY;
	}
}
