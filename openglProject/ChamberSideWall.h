#pragma once
#include "ChamberWall.h"
#include "HitboxGroup.h"
#include "PrismHitbox.h"

class ChamberSideWall :
	public ChamberWall
{
public:
	ChamberSideWall(ResourceManager* manager, ChamberWall::Position position);
	~ChamberSideWall();
	static const float DOOR_WIDTH;
	static const float DOOR_HEIGHT;

	// Inherited via ChamberWall
	virtual ModelFromFile * getModelWhenClosed() override;
	virtual ModelFromFile * getModelWhenOpen() override;
	virtual Hitbox * getHitboxWhenOpen() override;
	virtual Hitbox * getHitboxWhenClosed() override;
};

