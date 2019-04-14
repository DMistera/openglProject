#pragma once

#include "Camera.h"
#include <iostream>
#include <GLFW/glfw3.h>
#include "InputManager.h"

class Player
{
public:
	Player();
	void init(GLFWwindow* window);
	void update(GLFWwindow* window, double deltaTime);
	Camera* getCamera();
	~Player();
private:
	Camera* m_camera;
	glm::vec2 m_velocity;
	glm::vec2 m_startMousePos;
	float m_speed;
};

