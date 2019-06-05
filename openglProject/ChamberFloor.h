#pragma once

#include "ChamberWall.h"
#include "PrismHitbox.h"
#include "HitboxGroup.h"

class ChamberFloor : public ChamberWall
{
public:
	ChamberFloor(ResourceManager* manager, ChamberWall::Position position);
	~ChamberFloor();
	void open();
	static const float HOLE_SIZE;
private:

	// Inherited via ChamberWall
	virtual ModelFromFile * getModelWhenClosed() override;
	virtual ModelFromFile * getModelWhenOpen() override;
	virtual Hitbox * getHitboxWhenOpen() override;
	virtual Hitbox * getHitboxWhenClosed() override;
};

