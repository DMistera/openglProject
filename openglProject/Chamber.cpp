#include "Chamber.h"



Chamber::Chamber(ResourceManager* manager, Camera* camera, int x, int y, int z) : Entity()
{
	m_x = x;
	m_y = y;
	m_z = z;

	setPosition(glm::vec3(getFullSize()*m_x, getFullSize()*m_y, getFullSize()*m_z));

	m_leftWall = new ChamberSideWall(manager, ChamberWall::Position::LEFT);
	m_rightWall = new ChamberSideWall(manager, ChamberWall::Position::RIGHT);
	m_topWall = new ChamberSideWall(manager, ChamberWall::Position::FRONT);
	m_bottomWall = new ChamberSideWall(manager, ChamberWall::Position::BACK);
	m_floor = new ChamberFloor(manager, ChamberWall::Position::DOWN);
	m_ceiling = new ChamberFloor(manager, ChamberWall::Position::UP);

	addEntity(m_leftWall);
	addEntity(m_rightWall);
	addEntity(m_topWall);
	addEntity(m_bottomWall);
	addEntity(m_floor);
	addEntity(m_ceiling);

	m_leftWall->init(manager, camera);
	m_rightWall->init(manager, camera);
	m_topWall->init(manager, camera);
	m_bottomWall->init(manager, camera);
	m_floor->init(manager, camera);
	m_ceiling->init(manager, camera);
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

int Chamber::getX()
{
	return m_x;
}

int Chamber::getZ()
{
	return m_z;
}

int Chamber::getY()
{
	return m_y;
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
		case ChamberWall::Position::FRONT:
			m_topWall->open();
			break;
		case ChamberWall::Position::BACK:
			m_bottomWall->open();
			break;
		case ChamberWall::Position::UP:
			m_ceiling->open();
			break;
		case ChamberWall::Position::DOWN:
			m_floor->open();
			break;
	}
}

void Chamber::generateHitbox()
{

	m_doorFrameHitbox = new PrismHitbox(new Rectangle(getFullSize(), getFullSize()), getFullSize());

	m_hitbox.setParent(this);
	m_doorFrameHitbox->setParent(this);;

	m_leftWall->generateHitbox();
	m_rightWall->generateHitbox();
	m_topWall->generateHitbox();
	m_bottomWall->generateHitbox();
	m_floor->generateHitbox();
	m_ceiling->generateHitbox();

	m_hitbox.addHitbox(m_leftWall->getHitbox(), false);
	m_hitbox.addHitbox(m_rightWall->getHitbox(), false);
	m_hitbox.addHitbox(m_topWall->getHitbox(), false);
	m_hitbox.addHitbox(m_bottomWall->getHitbox(), false);
	m_hitbox.addHitbox(m_floor->getHitbox(), false);
	m_hitbox.addHitbox(m_ceiling->getHitbox(), false);
}

float Chamber::getFullSize()
{
	return chamberSize + ChamberWall::THICKNESS * 2;
}

void Chamber::fill(ResourceManager* manager, Camera* camera)
{
	HitboxGroup* hallwayHitbox = new HitboxGroup();
	hallwayHitbox->setParent(this);
	hallwayHitbox->addHitbox(new PrismHitbox(new Rectangle(chamberSize, ChamberSideWall::DOOR_WIDTH), chamberHeigth));
	hallwayHitbox->addHitbox(new PrismHitbox(new Rectangle(ChamberSideWall::DOOR_WIDTH, chamberSize), chamberHeigth));

	for (int i = 0; i < 40; i++) {
		float randSize = 0.05f + RANDOM.nextFloat()*0.1f ;
		float randX = RANDOM.nextFloat()*2.0f - 1.0f;
		float randZ = RANDOM.nextFloat()*2.0f - 1.0f;
		float randRot = RANDOM.nextFloat()*M_PI;
		WoodenBox* box = new WoodenBox(manager, camera);
		box->setScale(randSize);
		box->setPosition(glm::vec3(randX, 0.0f, randZ));
		box->setRotationY(randRot);
		box->setParent(this);
		Hitbox* boxHitbox = box->getHitbox();
		if (!boxHitbox->collide(hallwayHitbox) && !boxHitbox->collide(&m_hitbox)) {
			box->init(manager, camera);
			addEntity(box);
			m_hitbox.addHitbox(box->getHitbox(), false);
		}
		else {
			delete box;
		}
	}

	delete hallwayHitbox;

	if (m_ceiling->isOpen() || m_floor->isOpen()) {
		m_beam = new Beam(manager, camera);
		addEntity(m_beam);
	}
}

void Chamber::update(double deltaTime)
{
	if (hasBeam()) {
		m_beam->update(deltaTime);
	}
}

bool Chamber::hasBeam()
{
	return m_beam != nullptr;
}

Beam * Chamber::getBeam()
{
	return m_beam;
}

