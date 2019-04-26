#include "Map.h"



Map::Map()
{
}

void Map::generate(ResourceManager* manager)
{
	Model* chamberModel = manager->getModel("chamber.obj");
	for (float x = -5.0f; x < 5.0f; x+=2.4f) {
		for (float y = -5.0f; y < 5.0f; y+=2.4f) {
			BasicEntity* chamber = new BasicEntity(chamberModel);
			chamber->init(manager);
			chamber->setPosition(glm::vec3(x, 0.0f, y));
			m_entities.push_back(chamber);
		}
	}
}


Map::~Map()
{
}
