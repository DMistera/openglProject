#pragma once

#include "GameEngine.h"
#include "Player.h"

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
	Entity* m_sculpture;
	Entity* m_lightSource;
};

