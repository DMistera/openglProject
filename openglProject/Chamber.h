#pragma once

#include "MaterialEntity.h"
#include "ChamberWall.h"
#include "Circle.h"

#define _USE_MATH_DEFINES
#include <math.h>

class Chamber : public Entity
{
public:
	Chamber(ResourceManager* manager, Camera* camera, int x, int z);
	~Chamber();
	HitboxGroup* getHitbox();
	void addAdjacentChamber(Chamber* c);
	std::vector<Chamber*> getAdjacentChambers();
	float getX();
	float getZ();
	PrismHitbox* getDoorFrameHitbox();
	void open(ChamberWall::Position pos);
	void generateHitbox();
	float fullSize();
private:
	std::vector<Chamber*> m_adjacentChambers;
	HitboxGroup m_hitbox;
	PrismHitbox* m_doorFrameHitbox;
	int m_x;
	int m_z;

	ChamberWall* m_leftWall;
	ChamberWall* m_rightWall;
	ChamberWall* m_topWall;
	ChamberWall* m_bottomWall;
	MaterialEntity* m_floor;

	const float chamberSize = 2.0f;
	const float chamberHeigth = 2.0f;
};

