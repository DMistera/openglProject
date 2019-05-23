#pragma once
#include "HitboxGroup.h"
#include "PrismHitbox.h"



class ChamberWallHitbox : public HitboxGroup
{
public:
	ChamberWallHitbox(float width, float thickness, float height);
	~ChamberWallHitbox();
private:
	const float doorFrameWidth = 2.0f/3.0f;
	PrismHitbox* m_leftWall;
	PrismHitbox* m_rightWall;
	PrismHitbox* m_doorFrame;
};

