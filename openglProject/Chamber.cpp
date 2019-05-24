#include "Chamber.h"



Chamber::Chamber(ResourceManager* manager, int x, int z) : MaterialEntity(manager->getModel("chamber.obj"))
{
	m_x = x;
	m_z = z;

	float fullSize = chamberSize + wallWidth * 2;
	setPosition(glm::vec3(fullSize*m_x, 0.0f, fullSize*m_z));


	m_hitbox.setParent(this);
	m_doorFrameHitboxes.setParent(this);

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

	m_doorFrameHitboxes.addHitbox(leftWall->getDoorFrameHitbox(), false);
	m_doorFrameHitboxes.addHitbox(rightWall->getDoorFrameHitbox(), false);
	m_doorFrameHitboxes.addHitbox(topWall->getDoorFrameHitbox(), false);
	m_doorFrameHitboxes.addHitbox(bottomWall->getDoorFrameHitbox(), false);
}


Chamber::~Chamber()
{
}

HitboxGroup * Chamber::getHitbox()
{
	return &m_hitbox;
}

void Chamber::addAdjacentChamber(Chamber * c)
{
	m_adjacentChambers.push_back(c);
}

std::vector<Chamber*> Chamber::getAdjacentChambers()
{
	return m_adjacentChambers;
}

float Chamber::getX()
{
	return m_x;
}

float Chamber::getZ()
{
	return m_z;
}

HitboxGroup* Chamber::getDoorFrameHitboxes()
{
	return &m_doorFrameHitboxes;
}

