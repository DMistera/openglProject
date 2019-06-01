#include "ChamberWall.h"

const float ChamberWall::THICKNESS = 0.1f;

ChamberWall::ChamberWall(ResourceManager* manager, ChamberWall::Position position) : MaterialEntity(manager->getModel("closedWall.obj"))
{
	m_resourceManagerP = manager;
	m_position = position;
	float dx = (size + ChamberWall::THICKNESS) / 2.0f;
	if (position == TOP) {
		setPosition(glm::vec3(0.0f, 0.0f, -dx));
		setRotationY(M_PI);
	}
	else if (position == BOTTOM) {
		setPosition(glm::vec3(0.0f, 0.0f, dx));
	}
	else if (position == LEFT) {
		setPosition(glm::vec3(-dx, 0.0f, 0.0f));
		setRotationY(M_PI*(1.5f));
	}
	else if (position == RIGHT) {
		setPosition(glm::vec3(dx, 0.0f, 0.0f));
		setRotationY(M_PI*(0.5f));
	}

}


ChamberWall::~ChamberWall()
{
}

void ChamberWall::open()
{
	m_model = m_resourceManagerP->getModel("openWall.obj");
	m_open = true;
}

Hitbox * ChamberWall::getHitbox()
{
	return m_hitbox;
}

void ChamberWall::generateHitbox()
{
	if (m_open) {
		m_hitbox = new ChamberWallHitbox(size, ChamberWall::THICKNESS, size, doorWidth, doorHeight);
	}
	else {
		m_hitbox = new PrismHitbox(new Rectangle(size, ChamberWall::THICKNESS), size);
	}
	m_hitbox->setParent(this);
}
