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
	void setRotation(glm::vec2 rot);
	void move(glm::vec3 v);
	void moveTo(glm::vec3 v);
	void moveForward(float distance);
	void moveSideways(float distance);
	glm::mat4 getViewMatrix();
	glm::mat4 getPerspectiveMatrix();
	glm::vec3 getPosition();
private:
	glm::vec3 m_position = glm::vec3(0.0f);
	glm::vec3 m_target = glm::vec3(0.0f);
	glm::vec3 m_noseVector = glm::vec3(0.0f);
};