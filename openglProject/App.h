#pragma once

#include "GameEngine.h"

class App : public GameEngine
{
public:
	App();
	~App();

	// Inherited via GameEngine
	virtual void start() override;
	virtual void update(int time) override;
	virtual void draw(Renderer * renderer) override;

private:
	Camera* m_camera;
	Entity* m_cube;
};

