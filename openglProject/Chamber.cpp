#include "Chamber.h"


//TODO make floor and ceiling in blender and also add them
Chamber::Chamber(ResourceManager* manager, Camera* camera, int x, int z) : Entity()
{
	m_x = x;
	m_z = z;

	setPosition(glm::vec3(fullSize()*m_x, 0.0f, fullSize()*m_z));

	m_leftWall = new ChamberWall(manager, ChamberWall::Position::LEFT);
	m_rightWall = new ChamberWall(manager, ChamberWall::Position::RIGHT);
	m_topWall = new ChamberWall(manager, ChamberWall::Position::TOP);
	m_bottomWall = new ChamberWall(manager, ChamberWall::Position::BOTTOM);

	addEntity(m_leftWall);
	addEntity(m_rightWall);
	addEntity(m_topWall);
	addEntity(m_bottomWall);

	m_leftWall->init(manager, camera);
	m_rightWall->init(manager, camera);
	m_topWall->init(manager, camera);
	m_bottomWall->init(manager, camera);


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

void Chamber::open(ChamberWall::Position pos)
{
	switch (pos) {
	case ChamberWall::Position::LEFT:
		m_leftWall->open();
		break;
	case ChamberWall::Position::RIGHT:
		m_rightWall->open();
		break;
	case ChamberWall::Position::TOP:
		m_topWall->open();
		break;
	case ChamberWall::Position::BOTTOM:
		m_bottomWall->open();
		break;
	}
}

void Chamber::generateHitbox()
{

	m_doorFrameHitbox = new PrismHitbox(new Rectangle(fullSize(), fullSize()), fullSize());

	m_hitbox.setParent(this);
	m_doorFrameHitbox->setParent(this);;

	m_leftWall->generateHitbox();
	m_rightWall->generateHitbox();
	m_topWall->generateHitbox();
	m_bottomWall->generateHitbox();

	m_hitbox.addHitbox(m_leftWall->getHitbox(), false);
	m_hitbox.addHitbox(m_rightWall->getHitbox(), false);
	m_hitbox.addHitbox(m_topWall->getHitbox(), false);
	m_hitbox.addHitbox(m_bottomWall->getHitbox(), false);

	PrismHitbox* floor = new PrismHitbox(new Rectangle(fullSize(), fullSize()), -ChamberWall::THICKNESS, 0.0f);
	m_hitbox.addHitbox(floor);
}

float Chamber::fullSize()
{
	return chamberSize + ChamberWall::THICKNESS * 2;
}

