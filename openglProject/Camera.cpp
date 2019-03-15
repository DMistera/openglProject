#include "Camera.h"



Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::setPosition(glm::vec3 v)
{
	m_position = v;
}

void Camera::setTarget(glm::vec3 v)
{
	m_center = v;
}

void Camera::setNoseVector(glm::vec3 v)
{
	m_noseVector = v;
}

glm::mat4 Camera::getViewMatrix()
{
	glm::mat4 result = glm::lookAt(m_position, m_center, m_noseVector);
	return result;
}

glm::mat4 Camera::getPerspectiveMatrix()
{
	return glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
}
