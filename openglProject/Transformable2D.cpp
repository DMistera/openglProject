#include "Transformable2D.h"



Transformable2D::Transformable2D()
{
	m_position = glm::vec2(0.0f, 0.0f);
	m_scale = glm::vec2(1.0f, 1.0f);
	m_rotation = 0;
}


Transformable2D::~Transformable2D()
{
}

void Transformable2D::setPosition(glm::vec2 v)
{
	m_position = v;
}

void Transformable2D::setScale(glm::vec2 v)
{
	m_scale = v;
}

void Transformable2D::setRotation(float rot)
{
	m_rotation = rot;
}

glm::vec2 Transformable2D::getPosition()
{
	return m_position;
}

glm::vec2 Transformable2D::getScale()
{
	return m_scale;
}

float Transformable2D::getRotation()
{
	return m_rotation;
}

glm::vec2 Transformable2D::applyTransformation(glm::vec2 point)
{
	glm::vec2 result = point;
	//Apply scale
	result.x *= m_scale.x;
	result.y *= m_scale.y;
	//Apply rotation
	glm::mat2 rotationMatrix = glm::mat2(cos(m_rotation), -sin(m_rotation), sin(m_rotation), cos(m_rotation));
	result = rotationMatrix * result;
	//Apply transform
	result.x += m_position.x;
	result.y += m_position.y;
	return result;
}
