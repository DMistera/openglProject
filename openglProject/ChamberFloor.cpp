#include "ChamberFloor.h"

 const float ChamberFloor::HOLE_SIZE = SIZE * 1.0f / 3.0f;

ChamberFloor::ChamberFloor(ResourceManager* manager, ChamberWall::Position position) : ChamberWall(manager, position)
{
	if (position == UP) {
		setPosition(glm::vec3(0.0f, SIZE, 0.0f));
		setRotation(glm::vec3(M_PI, 0.0f, 0.0f));
	}
}


ChamberFloor::~ChamberFloor()
{
}

void ChamberFloor::open()
{
	m_model = m_resourceManagerP->getModel("OpenFloor.obj");
}


ModelFromFile * ChamberFloor::getModelWhenClosed()
{
	return m_resourceManagerP->getModel("Floor.obj");
}

ModelFromFile * ChamberFloor::getModelWhenOpen()
{
	return m_resourceManagerP->getModel("OpenFloor.obj");
}

/*
  *******
  * *** *
  * * * *
  * *** *
  *******
*/

Hitbox * ChamberFloor::getHitboxWhenOpen()
{
	HitboxGroup* result = new HitboxGroup();
	float hsh = HOLE_SIZE / 2.0f;
	float sh = (SIZE + THICKNESS*2) / 2.0f;
	result->addHitbox(new PrismHitbox(new Rectangle(glm::vec2(-sh, sh), glm::vec2(sh, hsh)), -THICKNESS, 0));
	result->addHitbox(new PrismHitbox(new Rectangle(glm::vec2(-sh, -sh), glm::vec2(sh, -hsh)), -THICKNESS, 0));
	result->addHitbox(new PrismHitbox(new Rectangle(glm::vec2(-sh, -hsh), glm::vec2(-hsh, hsh)), -THICKNESS, 0));
	result->addHitbox(new PrismHitbox(new Rectangle(glm::vec2(hsh, -hsh), glm::vec2(sh, hsh)), -THICKNESS, 0));
	return result;
}

Hitbox * ChamberFloor::getHitboxWhenClosed()
{
	return new PrismHitbox(new Rectangle(SIZE + THICKNESS*2, SIZE + THICKNESS*2), -THICKNESS, 0);
}
