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
	double m_cxPos, m_cyPos;
};

