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
	m_target = v;
}

void Camera::setNoseVector(glm::vec3 v)
{
	m_noseVector = v;
}

void Camera::setRotation(glm::vec2 rot)
{
	//TODO Fix the rotation (for first person)
	glm::mat4 m = glm::mat4(1.0f);
	m = glm::rotate(m, rot.x, glm::vec3(0.0f, 1.0f, 0.0f));
	m = glm::rotate(m, rot.y, glm::vec3(1.0f, 0.0f, 0.0f));
	//m = glm::translate(m, glm::vec3(0.0f, 0.0f, 1.0f));
	glm::vec3 forward = glm::vec3(m*glm::vec4(0.0f, 0.0f, -1.0f, 1.0f));
	//glm::rotate(forward, rot.y, glm::vec3(1.0f, 0.0f, 0.0f));
	m_target = m_position + forward;
}

void Camera::move(glm::vec3 v)
{
	m_position += v;
	m_target += v;
}

void Camera::moveForward(float distance)
{
	glm::vec3 direction = glm::normalize(m_target - m_position);
	direction.y = 0;
	move(distance * direction);
}

void Camera::moveSideways(float distance)
{
	glm::vec3 direction = glm::normalize(m_target - m_position);
	direction = glm::vec3(-direction.z, 0.0f, direction.x);
	move(distance * direction);
}

glm::mat4 Camera::getViewMatrix()
{
	glm::mat4 result = glm::lookAt(m_position, m_target, m_noseVector);
	return result;
}

glm::mat4 Camera::getPerspectiveMatrix()
{
	return glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
}

glm::vec3 Camera::getPosition()
{
	return m_position;
}
