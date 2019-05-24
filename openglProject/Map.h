#pragma once

#include "Entity.h"
#include "MaterialEntity.h"
#include "ResourceManager.h"
#include "Chamber.h"
#include "Player.h"

class Map : public Entity
{
public:
	Map();
	Chamber* getActiveChamber();
	void generate(ResourceManager* manager, Camera* camera);
	Chamber* getChamber(int x, int z);
	void setChamberAdjacents(Chamber* c);
	void checkActiveChamberChange(Player* p);
	~Map();
private:
	Chamber* m_activeChamber;
};

