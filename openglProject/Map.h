#pragma once

#include "Entity.h"
#include "MaterialEntity.h"
#include "ResourceManager.h"

class Map : public Entity
{
public:
	Map();
	void generate(ResourceManager* manager, Camera* camera);
	~Map();
};

