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
	return glm::lookAt(m_position, m_center, m_noseVector);
}

glm::mat4 Camera::getPerspectiveMatrix()
{
	return glm::perspective(50.0f*3.14f / 180.0f, 1.0f, 1.0f, 50.0f);
}
