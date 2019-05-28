#pragma once

#include "MaterialEntity.h"
#include "ChamberWallHitbox.h"
#include "ResourceManager.h"

#define _USE_MATH_DEFINES
#include <math.h>

class ChamberWall : public MaterialEntity
{
public:
	enum Position {
		TOP, BOTTOM, RIGHT, LEFT
	};
	ChamberWall(ResourceManager* manager, ChamberWall::Position position);
	~ChamberWall();
	void open();
private:
	ChamberWallHitbox* m_hitbox;
	bool m_open = false;
	ResourceManager* m_resourceManagerP;
	const float doorWidth = 2.0f / 5.0f;
	const float doorHeight = 4.0f / 5.0f;
	const float size = 2.0f;
	const float thickness = 0.1f;
	ChamberWall::Position m_position;
};

