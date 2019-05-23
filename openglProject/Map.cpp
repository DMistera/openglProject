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
	for (float x = 0.0f; x < 3.0f; x+=2.4f) {
		for (float y = 0.0f; y < 3.0f; y+=2.4f) {
			Chamber* chamber = new Chamber(manager);
			chamber->init(manager, camera);
			chamber->setPosition(glm::vec3(x, 0.0f, y));
			chamber->updateMatrix();
			m_entities.push_back(chamber);
		}
	}
	m_activeChamber = dynamic_cast<Chamber*>(m_entities[0]);
}


Map::~Map()
{
}
