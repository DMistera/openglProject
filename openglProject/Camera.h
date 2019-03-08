#pragma once

#include "Transformable.h"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class Camera : Transformable
{
public:
	Camera();
	~Camera();
	glm::mat4 getMatrix();
private:
	float m_fieldOfView;
	float m_aspect;
	float m_near;
	float m_far;
};