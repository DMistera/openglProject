#pragma once

#include "Program.h"
#include <GLFW/glfw3.h>
#include "Entity.h"
#include "Camera.h"

class Renderer
{
public:
	Renderer(GLFWwindow* window);
	bool init();
	void draw(Entity* entity);
	~Renderer();
private:
	GLFWwindow* m_window;
	Program* m_program;
	GLuint m_vertexBuffer;
};

