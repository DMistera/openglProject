#include "Transformable.h"



Transformable::Transformable()
{
	matrixOutdated = true;
}


Transformable::~Transformable()
{
}

glm::mat4 * Transformable::getMatrix()
{
	if (matrixOutdated) {
		updateMatrix();
	}
	return &m_matrix;
}

void Transformable::updateMatrix()
{
	glm::mat4 m = glm::mat4(1.0f);
	m = glm::translate(m, m_position);
	m = glm::rotate(m, m_rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	m = glm::rotate(m, m_rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	m = glm::rotate(m, m_rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	m = glm::scale(m, m_scale);
	if (m_parent != nullptr) {
		m_matrix = (*m_parent->getMatrix()) * m;
	}
	else {
		m_matrix = m;
	}
	matrixOutdated = false;
}

void Transformable::setParent(Transformable * parent)
{
	m_parent = parent;
}

void Transformable::setRotation(glm::vec3 v)
{
	m_rotation = v;
	matrixOutdated = true;
}

void Transformable::setPosition(glm::vec3 v)
{
	m_position = v;
	matrixOutdated = true;
}

void Transformable::setPosition(glm::vec2 v)
{
	setPosition(glm::vec3(v, 0.0f));
}

void Transformable::setScale(glm::vec3 v)
{
	m_scale = v;
	matrixOutdated = true;
}

void Transformable::setScale(glm::vec2 v)
{
	setScale(glm::vec3(v, 1.0f));
}

void Transformable::setScale(float scale)
{
	setScale(glm::vec3(scale, scale, scale));
}

void Transformable::move(glm::vec2 v)
{
	move(glm::vec3(v, 0.0f));
}

void Transformable::move(glm::vec3 v)
{
	setPosition(m_position + v);
}

glm::vec3 Transformable::getGlobalPosition()
{
	glm::mat4 matrix = *getMatrix();
	glm::vec3 result = matrix * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	return result;
}

glm::vec3 Transformable::getGlobalRotation()
{
	if (m_parent != nullptr) {
		return m_rotation + m_parent->getGlobalRotation();
	}
	else {
		return m_rotation;
	}
}
