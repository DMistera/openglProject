#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transformable
{
public:
	Transformable();
	~Transformable();
	glm::mat4 getMatrix();
protected:
	glm::vec3 m_position = glm::vec3(0.0f);
	glm::vec3 m_rotation = glm::vec3(0.0f);
	glm::vec3 m_scale = glm::vec3(1.0f, 1.0f, 1.0f);
};

