#include "Transformable.h"



Transformable::Transformable()
{
}


Transformable::~Transformable()
{
}

glm::mat4 Transformable::getMatrix()
{
	glm::mat4 m = glm::mat4(1.0f);
	m = glm::translate(m, m_position);
	m = glm::rotate(m, m_rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	m = glm::rotate(m, m_rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	m = glm::rotate(m, m_rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	m = glm::scale(m, m_scale);
	return m;
}

void Transformable::setRotation(glm::vec3 v)
{
	m_rotation = v;
}

void Transformable::setPosition(glm::vec3 v)
{
	m_position = v;
}

void Transformable::setPosition(glm::vec2 v)
{
	m_position = glm::vec3(v, 0.0f);
}

void Transformable::setScale(glm::vec3 v)
{
	m_scale = v;
}

void Transformable::setScale(glm::vec2 v)
{
	m_scale = glm::vec3(v, 1.0f);
}

void Transformable::setScale(float scale)
{
	setScale(glm::vec3(scale, scale, scale));
}

void Transformable::move(glm::vec3 v)
{
	m_position += v;
}

glm::vec2 Transformable::getPositionV2()
{
	return glm::vec2(m_position);
}

glm::vec2 Transformable::getScaleV2()
{
	return glm::vec2(m_scale);
}
