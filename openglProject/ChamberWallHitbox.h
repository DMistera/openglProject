#pragma once
#include "HitboxGroup.h"
#include "PrismHitbox.h"



class ChamberWallHitbox : public HitboxGroup
{
public:
	ChamberWallHitbox(float width, float thickness, float height, float DOOR_WIDTH, float DOOR_HEIGHT);
	~ChamberWallHitbox();
	PrismHitbox* getDoorFrameHitbox();
private:
	PrismHitbox* m_leftWall;
	PrismHitbox* m_rightWall;
	PrismHitbox* m_doorFrame;
	PrismHitbox* m_doorFrameWall;
};

