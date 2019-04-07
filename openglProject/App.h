#pragma once

#include "GameEngine.h"
#include "Player.h"
#include "BasicEntity.h"

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
	BasicEntity* m_sculpture;
	Entity* m_lightEntity;
	LightSource* m_lightSource;
	Entity* m_lightEntity2;
	LightSource* m_lightSource2;
};

