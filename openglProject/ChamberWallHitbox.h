#pragma once
#include "HitboxGroup.h"
#include "PrismHitbox.h"



class ChamberWallHitbox : public HitboxGroup
{
public:
	ChamberWallHitbox(float width, float thickness, float height);
	~ChamberWallHitbox();
	PrismHitbox* getDoorFrameHitbox();
private:
	const float doorWidth = 2.0f/3.0f;
	const float doorHeight = 4.0f / 3.0f;
	PrismHitbox* m_leftWall;
	PrismHitbox* m_rightWall;
	PrismHitbox* m_doorFrame;
	PrismHitbox* m_doorFrameWall;
};

