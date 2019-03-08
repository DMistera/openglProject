#include "Camera.h"



Camera::Camera()
{
}


Camera::~Camera()
{
}

glm::mat4 Camera::getMatrix()
{
	return glm::perspective(m_fieldOfView, m_aspect, m_near, m_far);
}
