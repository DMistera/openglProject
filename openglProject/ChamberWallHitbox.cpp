#include "ChamberWallHitbox.h"



ChamberWallHitbox::ChamberWallHitbox(float width, float thickness, float height, float DOOR_WIDTH, float DOOR_HEIGHT)
{

	float leftX = - DOOR_WIDTH / 2.0f;
	float rightX = DOOR_WIDTH / 2.0f;
	float mostLeftX = -width / 2.0f;
	float mostRightX = width / 2.0f;
	float wallWidth = mostRightX - rightX;
	float middleLeftX = (leftX + mostLeftX) / 2.0f;
	float middleRightX = (rightX + mostRightX) / 2.0f;
	m_leftWall = new PrismHitbox(new Rectangle(wallWidth, thickness), 0, height);
	m_leftWall->setPosition(glm::vec3(middleLeftX, 0.0f, 0.0f));
	m_rightWall = new PrismHitbox(new Rectangle(wallWidth, thickness), 0, height);
	m_rightWall->setPosition(glm::vec3(middleRightX, 0.0f, 0.0f));
	float doorFrameWallHeight = height - DOOR_HEIGHT;
	m_doorFrameWall = new PrismHitbox(new Rectangle(DOOR_WIDTH, thickness), height - doorFrameWallHeight, height);
	m_doorFrame = new PrismHitbox(new Rectangle(DOOR_WIDTH, thickness), 0, height);
	m_doorFrame->setParent(this);
	addHitbox(m_leftWall);
	addHitbox(m_rightWall); 
	addHitbox(m_doorFrameWall);
}

ChamberWallHitbox::~ChamberWallHitbox()
{
}

PrismHitbox * ChamberWallHitbox::getDoorFrameHitbox()
{
	return m_doorFrame;
}
