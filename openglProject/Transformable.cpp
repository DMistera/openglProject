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
	m = glm::rotate(m, m_position.x, glm::vec3(1.0f, 0.0f, 0.0f));
	m = glm::rotate(m, m_position.y, glm::vec3(0.0f, 1.0f, 0.0f));
	m = glm::rotate(m, m_position.z, glm::vec3(0.0f, 0.0f, 1.0f));
	m = glm::scale(m, m_scale);
	return m;
}
