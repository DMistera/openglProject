#pragma once

#include "Entity.h"
#include "MaterialEntity.h"
#include "ResourceManager.h"
#include "Chamber.h"

class Map : public Entity
{
public:
	Map();
	Chamber* getActiveChamber();
	void generate(ResourceManager* manager, Camera* camera);
	~Map();
private:
	Chamber* m_activeChamber;
};

