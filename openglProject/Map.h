#pragma once

#include "Entity.h"
#include "MaterialEntity.h"
#include "ResourceManager.h"
#include "Chamber.h"
#include "Player.h"
#include <algorithm> 
#include <ctime> 

class Map : public Entity
{
public:
	Map();
	Chamber* getActiveChamber();
	void generate(ResourceManager* manager, Camera* camera);
	Chamber* getChamber(int x, int y, int z);
	void addChamber(Chamber* c);
	void setChamberAdjacents(Chamber* c);
	void checkActiveChamberChange(Player* p);
	~Map();
	void updateAll(double deltaTime);
private:
	Chamber* m_activeChamber;
	void generateMaze();
	int linearise(int x, int y, int z);
	const int maxX = 3;
	const int maxY = 3;
	const int maxZ = 3;
};

