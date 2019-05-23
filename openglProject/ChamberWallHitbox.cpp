#include "ChamberWallHitbox.h"



ChamberWallHitbox::ChamberWallHitbox(float width, float thickness, float height)
{

	float leftX = - doorFrameWidth / 2.0f;
	float rightX = doorFrameWidth / 2.0f;
	float mostLeftX = -width / 2.0f;
	float mostRightX = width / 2.0f;
	float wallWidth = mostRightX - rightX;
	float middleLeftX = (leftX + mostLeftX) / 2.0f;
	float middleRightX = (rightX + mostRightX) / 2.0f;
	m_leftWall = new PrismHitbox(new Rectangle(wallWidth, thickness), 0, height);
	m_leftWall->setPosition(glm::vec3(middleLeftX, 0.0f, 0.0f));
	m_rightWall = new PrismHitbox(new Rectangle(wallWidth, thickness), 0, height);
	m_rightWall->setPosition(glm::vec3(middleRightX, 0.0f, 0.0f));
	m_doorFrame = new PrismHitbox(new Rectangle(doorFrameWidth, thickness), 0, height);
	addHitbox(m_leftWall);
	addHitbox(m_rightWall);
}

ChamberWallHitbox::~ChamberWallHitbox()
{
}
