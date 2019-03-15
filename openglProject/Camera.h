#pragma once

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	Camera();
	~Camera();
	void setPosition(glm::vec3 v);
	void setTarget(glm::vec3 v);
	void setNoseVector(glm::vec3 v);
	glm::mat4 getViewMatrix();
	glm::mat4 getPerspectiveMatrix();
private:
	glm::vec3 m_position;
	glm::vec3 m_center;
	glm::vec3 m_noseVector;
};