#include "Hitbox.h"



Hitbox::Hitbox()
{
}


Hitbox::~Hitbox()
{
}

bool Hitbox::collide(Hitbox* other)
{
	if (collideY(other)) {
		return collide2D(other);
	}
	else {
		return false;
	}
}

float Hitbox::getMinY()
{
	return m_minY;
}

float Hitbox::getMaxY()
{
	return m_maxY;
}

bool Hitbox::collideY(Hitbox * other)
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
