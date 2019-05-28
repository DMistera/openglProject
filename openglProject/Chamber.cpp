#include "Chamber.h"



Chamber::Chamber(ResourceManager* manager, int x, int z) : MaterialEntity(manager->getModel("chamber.obj"))
{
	m_x = x;
	m_z = z;

	float fullSize = chamberSize + wallWidth * 2;
	setPosition(glm::vec3(fullSize*m_x, 0.0f, fullSize*m_z));

	m_doorFrameHitbox = new PrismHitbox(new Rectangle(fullSize, fullSize), fullSize);

	m_hitbox.setParent(this);
	m_doorFrameHitbox->setParent(this);

	float hs = chamberSize / 2.0f + wallWidth / 2.0f;
	float doorWidth = 2.0f / 3.0f;
	float doorHeight = 4.0f / 3.0f;

	ChamberWallHitbox* leftWall = new ChamberWallHitbox(chamberSize, wallWidth, chamberHeigth, doorWidth, doorHeight);
	ChamberWallHitbox* rightWall = new ChamberWallHitbox(chamberSize, wallWidth, chamberHeigth, doorWidth, doorHeight);
	ChamberWallHitbox* topWall = new ChamberWallHitbox(chamberSize, wallWidth, chamberHeigth, doorWidth, doorHeight);
	ChamberWallHitbox* bottomWall = new ChamberWallHitbox(chamberSize, wallWidth, chamberHeigth, doorWidth, doorHeight);

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

	float floorSize = chamberSize + wallWidth * 2;
	PrismHitbox* floor = new PrismHitbox(new Rectangle(floorSize, floorSize), -wallWidth, 0.0f);
	m_hitbox.addHitbox(floor);

	/*m_doorFrameHitbox.addHitbox(leftWall->getDoorFrameHitbox(), false);
	m_doorFrameHitbox.addHitbox(rightWall->getDoorFrameHitbox(), false);
	m_doorFrameHitbox.addHitbox(topWall->getDoorFrameHitbox(), false);
	m_doorFrameHitbox.addHitbox(bottomWall->getDoorFrameHitbox(), false);*/
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

PrismHitbox* Chamber::getDoorFrameHitbox()
{
	return m_doorFrameHitbox;
}

