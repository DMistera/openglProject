#pragma once

#include "Renderer.h"

class GameEngine
{
public:
	GameEngine();
	~GameEngine();
	virtual void start() = 0;
	virtual void update(double time) = 0;
	virtual void draw(Renderer* renderer) = 0;
};

