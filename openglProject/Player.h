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
	void update(double deltaTime, Chamber * currentChamber);
	void resolveHitbox(Chamber* currentChamber);
	Camera* getCamera();
	LightSource* getLightSource();
	PrismHitbox* getHitbox();
	~Player();
private:
	glm::vec3 getShiftVector(double deltaTime);
	void updateHitboxPosiiton(Camera* cam);

	LightSource* m_lightSource;
	glm::vec3 m_velocity;
	float m_speed;
	const float gravityAcceleration = -6.5f;
	bool m_canJump = true;
	bool m_spacePressed = false;
	void spaceAction();

	PrismHitbox m_hitbox = PrismHitbox(new Circle(0.15f), 0.6f);
	glm::vec3 m_lastHitboxShift;

	//Camera
	Camera* m_camera;
	const float m_cameraSpeed = (1.0f / 400.0f);
	glm::vec2 m_mousePos;
	glm::vec2 m_cameraAngle;
	const float playerHeight = 0.4f;
};
