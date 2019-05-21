#include "Chamber.h"



Chamber::Chamber(ResourceManager* manager) : MaterialEntity(manager->getModel("chamber.obj"))
{
	m_hitbox.setParent(this);

	float hs = chamberSize / 2.0f;
	ChamberWallHitbox* leftWall = new ChamberWallHitbox(glm::vec2(-hs - wallWidth, hs ), glm::vec2(-hs, -hs), false, chamberHeigth);
	ChamberWallHitbox* rightWall = new ChamberWallHitbox(glm::vec2(hs, hs), glm::vec2(hs + wallWidth, -hs), false, chamberHeigth);
	ChamberWallHitbox* topWall = new ChamberWallHitbox(glm::vec2(-hs, hs + wallWidth), glm::vec2(hs, hs), true, chamberHeigth);
	ChamberWallHitbox* bottomWall = new ChamberWallHitbox(glm::vec2(-hs, -hs), glm::vec2(hs, -hs - wallWidth), true, chamberHeigth);

	m_hitbox.addHitbox(leftWall);
	m_hitbox.addHitbox(rightWall);
	m_hitbox.addHitbox(topWall);
	m_hitbox.addHitbox(bottomWall);
}


Chamber::~Chamber()
{
}

HitboxGroup * Chamber::getHitbox()
{
	return &m_hitbox;
}

