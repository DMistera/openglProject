#include "Transformable.h"



Transformable::Transformable()
{
}


Transformable::~Transformable()
{
}

glm::mat4 Transformable::getMatrix()
{
	glm::mat4 m = glm::mat4(1);
	m = glm::translate(m, m_position);
	m = glm::rotate(m, m_position.x, glm::vec3(1, 0, 0));
	m = glm::rotate(m, m_position.y, glm::vec3(0, 1, 0));
	m = glm::rotate(m, m_position.z, glm::vec3(0, 0, 1));
	m = glm::scale(m, m_scale);
	return m;
}
