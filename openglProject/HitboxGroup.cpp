#include "HitboxGroup.h"



HitboxGroup::HitboxGroup()
{
}


HitboxGroup::~HitboxGroup()
{
}

void HitboxGroup::addHitbox(Hitbox * hitbox)
{
	m_hitboxes.push_back(hitbox);
	hitbox->setParent(this);
}

std::vector<Hitbox*> HitboxGroup::getChildren()
{
	return m_hitboxes;
}

Hitbox::Type HitboxGroup::getType()
{
	return Hitbox::Type::GROUP;
}
