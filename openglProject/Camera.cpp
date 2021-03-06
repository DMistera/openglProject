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
	glm::mat4 m = glm::mat4(1.0f);
	m = glm::rotate(m, rot.x, glm::vec3(0.0f, 1.0f, 0.0f));
	m = glm::rotate(m, rot.y, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::vec3 forward = glm::vec3(m*glm::vec4(0.0f, 0.0f, -1.0f, 1.0f));
	m_target = m_position + forward;
}

void Camera::move(glm::vec3 v)
{
	m_position += v;
	m_target += v;
}

void Camera::moveTo(glm::vec3 v)
{
	glm::vec3 diff = v - m_position;
	move(diff);
}

void Camera::moveForward(float distance)
{
	glm::vec3 direction = m_target - m_position;
	direction.y = 0;
	direction = glm::normalize(direction);
	move(distance * direction);
}

void Camera::moveSideways(float distance)
{
	glm::vec3 direction = (m_target - m_position);
	direction.y = 0;
	direction = glm::normalize(direction);
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
	return glm::perspective(glm::radians(60.0f), 1.5f, 0.1f, 100.0f);
}

glm::vec3 Camera::getPosition()
{
	return m_position;
}
