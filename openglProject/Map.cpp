#include "Map.h"



Map::Map()
{
}

void Map::generate(ResourceManager* manager, Camera* camera)
{
	Model* chamberModel = manager->getModel("chamber.obj");
	for (float x = -5.0f; x < 50.0f; x+=2.4f) {
		for (float y = -5.0f; y < 50.0f; y+=2.4f) {
			MaterialEntity* chamber = new MaterialEntity(chamberModel);
			chamber->init(manager, camera);
			chamber->setPosition(glm::vec3(x, 0.0f, y));
			m_entities.push_back(chamber);
		}
	}
}


Map::~Map()
{
}
