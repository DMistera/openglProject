#include "Chamber.h"



Chamber::Chamber(ResourceManager* manager) : MaterialEntity(manager->getModel("chamber.obj"))
{
	m_hitbox.setParent(this);

	float hs = chamberSize / 2.0f + wallWidth / 2.0f;

	ChamberWallHitbox* leftWall = new ChamberWallHitbox(chamberSize, wallWidth, chamberHeigth);
	ChamberWallHitbox* rightWall = new ChamberWallHitbox(chamberSize, wallWidth, chamberHeigth);
	ChamberWallHitbox* topWall = new ChamberWallHitbox(chamberSize, wallWidth, chamberHeigth);
	ChamberWallHitbox* bottomWall = new ChamberWallHitbox(chamberSize, wallWidth, chamberHeigth);

	leftWall->setPosition(glm::vec3(-hs, 0.0f, 0.0f));
	rightWall->setPosition(glm::vec3(hs, 0.0f, 0.0f));
	topWall->setPosition(glm::vec3(0.0f, 0.0f, -hs));
	bottomWall->setPosition(glm::vec3(0.0f, 0.0f, hs));

	leftWall->setRotation(glm::vec3(0.0f, M_PI / 2.0f, 0.0f));
	rightWall->setRotation(glm::vec3(0.0f, M_PI / 2.0f, 0.0f));

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

