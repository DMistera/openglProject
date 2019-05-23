#pragma once

#include "MaterialEntity.h"
#include "ChamberWallHitbox.h"
#include "Circle.h"

#define _USE_MATH_DEFINES
#include <math.h>

class Chamber : public MaterialEntity
{
public:
	Chamber(ResourceManager* manager);
	~Chamber();
	HitboxGroup* getHitbox();
private:
	HitboxGroup m_hitbox;
	const float chamberSize = 2.0f;
	const float wallWidth = 0.2f;
	const float chamberHeigth = 2.0f;
};

