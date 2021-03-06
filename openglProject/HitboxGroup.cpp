#include "HitboxGroup.h"



HitboxGroup::HitboxGroup()
{
}


HitboxGroup::~HitboxGroup()
{
	for (Hitbox* h : m_hitboxes) {
		delete h;
	}
	m_hitboxes.clear();
}

void HitboxGroup::addHitbox(Hitbox * hitbox, bool setParent )
{
	m_hitboxes.push_back(hitbox);
	if (setParent) {
		hitbox->setParent(this);
	}
}

std::vector<Hitbox*> HitboxGroup::getChildren()
{
	return m_hitboxes;
}

Hitbox::Type HitboxGroup::getType()
{
	return Hitbox::Type::GROUP;
}

bool HitboxGroup::isPointInside(glm::vec3 p)
{
	for (Hitbox* h : m_hitboxes) {
		if (h->isPointInside(p)) {
			return true;
		}
	}
	return false;
}

void HitboxGroup::draw(ResourceManager * resourceManger, Camera * camera)
{
	for (int i = 0; i < m_hitboxes.size(); i++) {
		m_hitboxes[i]->draw(resourceManger, camera);
	}
}
