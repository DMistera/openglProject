#pragma once

#include "Renderer.h"

class GameEngine
{
public:
	GameEngine();
	~GameEngine();
	void init(GLFWwindow* window);
	virtual void start() = 0;
	virtual void update(double time) = 0;
	virtual void draw(Renderer* renderer) = 0;
protected:
	GLFWwindow* m_window;
};

