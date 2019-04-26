#pragma once

#include "GameEngine.h"
#include "Player.h"
#include "BasicEntity.h"
#include "Map.h"

#define _USE_MATH_DEFINES
#include <math.h>

class App : public GameEngine
{
public:
	App();
	~App();

	// Inherited via GameEngine
	virtual void start() override;
	virtual void update(double time) override;
	virtual void draw(Renderer * renderer) override;

private:
	Player* m_player;
	Map* m_map;
};

