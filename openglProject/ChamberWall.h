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
	Hitbox* getHitbox();
	void generateHitbox();
	static const float THICKNESS;
	static const float DOOR_WIDTH;
	static const float DOOR_HEIGHT;
private:
	Hitbox* m_hitbox;
	bool m_open = false;
	ResourceManager* m_resourceManagerP;
	const float size = 2.0f;
	ChamberWall::Position m_position;
};

