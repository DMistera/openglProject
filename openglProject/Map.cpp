#include "Map.h"



Map::Map()
{
}

Chamber * Map::getActiveChamber()
{
	return m_activeChamber;
}

void Map::generate(ResourceManager* manager, Camera* camera)
{
	ModelFromFile* chamberModel = manager->getModel("chamber.obj");
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			Chamber* chamber = new Chamber(manager, x, y);
			chamber->init(manager, camera);
			chamber->updateMatrix();
			m_entities.push_back(chamber);
		}
	}
	for (Entity* e : m_entities) {
		setChamberAdjacents(dynamic_cast<Chamber*>(e));
	}
	m_activeChamber = dynamic_cast<Chamber*>(m_entities[0]);
}

Chamber * Map::getChamber(int x, int z)
{
	for (Entity* e : m_entities) {
		Chamber* c = dynamic_cast<Chamber*>(e);
		if (c->getX() == x && c->getZ() == z) {
			return c;
		}
	}
	return nullptr;
}

void Map::setChamberAdjacents(Chamber * c)
{
	int x = c->getX();
	int z = c->getZ();
	Chamber* c1 = getChamber(x + 1, z);
	Chamber* c2 = getChamber(x - 1, z);
	Chamber* c3 = getChamber(x, z + 1);
	Chamber* c4 = getChamber(x, z - 1);
	if (c1 != nullptr) {
		c->addAdjacentChamber(c1);
	}
	if (c2 != nullptr) {
		c->addAdjacentChamber(c2);
	}
	if (c3 != nullptr) {
		c->addAdjacentChamber(c3);
	}
	if (c4 != nullptr) {
		c->addAdjacentChamber(c4);
	}
}

void Map::checkActiveChamberChange(Player * p)
{
	for (Chamber* c : m_activeChamber->getAdjacentChambers()) {
		//if (p->getHitbox()->collide(c->getDoorFrameHitboxes())) {
		if (c->getDoorFrameHitbox()->isPointInside(p->getHitbox()->getGlobalPosition() + glm::vec3(0.0f, 0.5f, 0.0f))) {
			m_activeChamber = c;
		}
	}
}




Map::~Map()
{
}
