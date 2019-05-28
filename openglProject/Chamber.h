#pragma once

#include "MaterialEntity.h"
#include "ChamberWallHitbox.h"
#include "Circle.h"

#define _USE_MATH_DEFINES
#include <math.h>

class Chamber : public MaterialEntity
{
public:
	Chamber(ResourceManager* manager, int x, int z);
	~Chamber();
	HitboxGroup* getHitbox();
	void addAdjacentChamber(Chamber* c);
	std::vector<Chamber*> getAdjacentChambers();
	float getX();
	float getZ();
	PrismHitbox* getDoorFrameHitbox();
private:
	std::vector<Chamber*> m_adjacentChambers;
	HitboxGroup m_hitbox;
	PrismHitbox* m_doorFrameHitbox;
	int m_x;
	int m_z;

	const float chamberSize = 2.0f;
	const float wallWidth = 0.2f;
	const float chamberHeigth = 2.0f;
};

