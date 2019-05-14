#include "Chamber.h"



Chamber::Chamber(ResourceManager* manager) : MaterialEntity(manager->getModel("chamber.obj"))
{
	m_hitbox.getBase()->setParent(this);
}


Chamber::~Chamber()
{
}

PrismHitbox * Chamber::getHitbox()
{
	return &m_hitbox;
}

void Chamber::updateMatrix()
{
	Transformable::updateMatrix();
	m_hitbox.getBase()->updateMatrix();
}
