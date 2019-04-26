#pragma once

#include "Camera.h"
#include <iostream>
#include <GLFW/glfw3.h>
#include "InputManager.h"
#include "LightSource.h"
#define _USE_MATH_DEFINES
#include <math.h>

class Player
{
public:
	Player();
	void init(GLFWwindow* window);
	void update(GLFWwindow* window, double deltaTime);
	Camera* getCamera();
	LightSource* getLightSource();
	~Player();
private:
	LightSource* m_lightSource;
	glm::vec2 m_velocity;
	float m_speed;

	//Camera
	Camera* m_camera;
	const float m_cameraSpeed = (1.0f / 400.0f);
	glm::vec2 m_mousePos;
	glm::vec2 m_cameraAngle;
};
