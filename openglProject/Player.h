#pragma once

#include "Chamber.h"
#include "Camera.h"
#include <iostream>
#include <GLFW/glfw3.h>
#include "InputManager.h"
#include "LightSource.h"
#include "PrismHitbox.h"

#define _USE_MATH_DEFINES
#include <math.h>

class Player
{
public:
	Player();
	void init(GLFWwindow* window);
	void update(GLFWwindow* window, double deltaTime, Chamber* currentChamber);
	Camera* getCamera();
	LightSource* getLightSource();
	~Player();
private:
	glm::vec3 getShiftVector(double deltaTime);
	void updateHitboxPosiiton(Camera* cam);

	LightSource* m_lightSource;
	glm::vec2 m_velocity;
	float m_speed;

	PrismHitbox m_hitbox = PrismHitbox(new Circle(0.15f), 0.0f, 1.0f);

	//Camera
	Camera* m_camera;
	const float m_cameraSpeed = (1.0f / 400.0f);
	glm::vec2 m_mousePos;
	glm::vec2 m_cameraAngle;
};
