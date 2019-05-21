#pragma once
#include "HitboxGroup.h"
#include "PrismHitbox.h"

class ChamberWallHitbox :
	public HitboxGroup
{
public:
	ChamberWallHitbox(glm::vec2 a, glm::vec2 b, bool horizontal, float height);
	~ChamberWallHitbox();
private:
	const float doorFrameWidth = 0.33333f;
	PrismHitbox* m_leftWall;
	PrismHitbox* m_rightWall;
	PrismHitbox* m_doorFrame;
};

