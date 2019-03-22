#include "Renderer.h"



Renderer::Renderer(GLFWwindow* window)
{
	m_window = window;
}

bool Renderer::init()
{
	GLuint vertexArrayID = 0;
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);
	glEnable(GL_DEPTH_TEST);
	return true;
}

void Renderer::draw(Entity* entity, Camera* camera)
{
	entity->draw(camera);
	int err;
	if ((err = glGetError())) {
		std::cerr << "OpenGL error number " << err;
	}
}


Renderer::~Renderer()
{
}
