#include "WoodenBox.h"



WoodenBox::WoodenBox(ResourceManager* manager, Camera* camera) : MaterialEntity()
{

	m_hitbox = new PrismHitbox(new Rectangle(2.0f, 2.0f), 2.0f);
	m_hitbox->setParent(this);
}


WoodenBox::~WoodenBox()
{
}

PrismHitbox * WoodenBox::getHitbox()
{
	return m_hitbox;
}

ModelFromFile * WoodenBox::setModel(ResourceManager * res)
{
	return res->getModel("Box.obj");
}
