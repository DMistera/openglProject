#pragma once

#include "Entity.h"
#include "BasicEntity.h"
#include "ResourceManager.h"

class Map : public Entity
{
public:
	Map();
	void generate(ResourceManager* manager);
	~Map();
};

