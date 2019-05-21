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

bool PrismHitbox::collidePrism(PrismHitbox * other)
{
	if (collideY(other)) {
		glm::vec3 g = getGlobalPosition();
		m_base->setPosition(glm::vec2(g.x, -g.z));
		glm::vec3 g2 = other->getGlobalPosition();
		Shape* otherBase = other->getBase();
		otherBase->setPosition(glm::vec2(g2.x, -g2.z));
		if (Intersecter2D::intersect(m_base, otherBase)) {
			return true;
		}
	}
	return false;
}

void PrismHitbox::setPosition(glm::vec3 v)
{
	Transformable::setPosition(v);
	m_base->setPosition(glm::vec2(v.x, -v.z));
}

void PrismHitbox::setRotation(glm::vec3 v)
{
	Transformable::setRotation(v);
	m_base->setRotation(v.y);
}

void PrismHitbox::setScale(glm::vec3 v)
{
	Transformable::setScale(v);
	m_base->setScale(glm::vec2(v.x, v.y));
}

void PrismHitbox::inheritBasePosition()
{
	glm::vec2 basePos = m_base->getPosition();
	setPosition(glm::vec3(basePos.x, m_position.y, -basePos.y));
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

Hitbox::Type PrismHitbox::getType()
{
	return Hitbox::Type::PRISM;
}
