#include "ChamberWall.h"



ChamberWall::ChamberWall(ResourceManager* manager, ChamberWall::Position position) : MaterialEntity(manager->getModel("closedWall.obj"))
{
	m_resourceManagerP = manager;
	m_position = position;
	float dx = (size + thickness) / 2.0f;
	if (position == TOP) {
		setPosition(glm::vec3(0.0f, 0.0f, dx));
	}
	else if (position == BOTTOM) {
		setPosition(glm::vec3(0.0f, 0.0f, -dx));
		setRotationY(M_PI);
	}
	else if (position == LEFT) {
		setPosition(glm::vec3(dx, 0.0f, 0.0f));
		setRotationY(M_PI*(0.5f));
	}
	else if (position == RIGHT) {
		setPosition(glm::vec3(-dx, 0.0f, 0.0f));
		setRotationY(M_PI*(1.5f));
	}
}


ChamberWall::~ChamberWall()
{
}

void ChamberWall::open()
{
	m_model = m_resourceManagerP->getModel("openWall.obj");
}
