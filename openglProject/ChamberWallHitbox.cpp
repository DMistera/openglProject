#include "ChamberWallHitbox.h"



ChamberWallHitbox::ChamberWallHitbox(glm::vec2 a, glm::vec2 b, bool horizontal, float height)
{
	if (horizontal) {
		float middle = (a.x + b.y) / 2.0f;
		float leftX = middle - doorFrameWidth / 2.0f;
		float rightX = middle + doorFrameWidth / 2.0f;
		m_leftWall = new PrismHitbox(new Rectangle(a, glm::vec2(leftX, b.y)), 0, height);
		m_rightWall = new PrismHitbox(new Rectangle(glm::vec2(rightX, a.y), b), 0, height);
		m_doorFrame = new PrismHitbox(new Rectangle(glm::vec2(leftX, a.y), glm::vec2(rightX, b.y)), 0, height);
	}
	//Vertical
	else {
		float middle = (a.y + b.y)/2.0f;
		float leftY = middle - doorFrameWidth / 2.0f;
		float rightY = middle + doorFrameWidth / 2.0f;
		m_leftWall = new PrismHitbox(new Rectangle(a, glm::vec2(b.x, leftY)), 0, height);
		m_rightWall = new PrismHitbox(new Rectangle(glm::vec2(a.x, rightY), b), 0, height);
		m_doorFrame = new PrismHitbox(new Rectangle(glm::vec2(a.x, leftY), glm::vec2(b.x, rightY)), 0, height);
	}
	m_leftWall->inheritBasePosition();
	m_rightWall->inheritBasePosition();
	m_doorFrame->inheritBasePosition();
	addHitbox(m_leftWall);
	addHitbox(m_rightWall);
	addHitbox(m_doorFrame);
}

ChamberWallHitbox::~ChamberWallHitbox()
{
}
