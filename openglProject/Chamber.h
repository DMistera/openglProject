#pragma once

#include "MaterialEntity.h"
#include "ChamberSideWall.h"
#include "ChamberFloor.h"
#include "Circle.h"
#include "WoodenBox.h"
#include "Utils.h"


#define _USE_MATH_DEFINES
#include <math.h>

class Chamber : public Entity
{
public:
	Chamber(ResourceManager* manager, Camera* camera, int x, int y, int z);
	~Chamber();
	HitboxGroup* getHitbox();
	void addAdjacentChamber(Chamber* c);
	std::vector<Chamber*> getAdjacentChambers();
	int getX();
	int getZ();
	int getY();
	PrismHitbox* getDoorFrameHitbox();
	void open(ChamberWall::Position pos);
	void generateHitbox();
	float getFullSize();
	void fill(ResourceManager* manager, Camera* camera);
private:
	std::vector<Chamber*> m_adjacentChambers;
	HitboxGroup m_hitbox;
	PrismHitbox* m_doorFrameHitbox;
	int m_x;
	int m_y;
	int m_z;

	ChamberWall* m_leftWall;
	ChamberWall* m_rightWall;
	ChamberWall* m_topWall;
	ChamberWall* m_bottomWall;
	ChamberWall* m_floor;
	ChamberWall* m_ceiling;

	const float chamberSize = 2.0f;
	const float chamberHeigth = 2.0f;
};

