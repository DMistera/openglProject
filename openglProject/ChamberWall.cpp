#include "ChamberWall.h"

const float ChamberWall::SIZE = 2.0f;
const float ChamberWall::THICKNESS = 0.1f;

ChamberWall::ChamberWall(ResourceManager* manager, ChamberWall::Position position)
{
	m_resourceManagerP = manager;
	m_position = position;
	m_open = false;
}


ChamberWall::~ChamberWall()
{
}

void ChamberWall::open()
{
	m_model = getModelWhenOpen();
	m_open = true;
}

Hitbox * ChamberWall::getHitbox()
{
	return m_hitbox;
}

void ChamberWall::generateHitbox()
{
	if (m_open) {
		m_hitbox = getHitboxWhenOpen();
	}
	else {
		m_hitbox = getHitboxWhenClosed();
	}
	m_hitbox->setParent(this);
}

ModelFromFile * ChamberWall::setModel(ResourceManager * res)
{
	if (m_open) {
		return getModelWhenOpen();
	}
	else {
		return getModelWhenClosed();
	}
}
