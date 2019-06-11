#include "Renderer.h"



Renderer::Renderer(GLFWwindow* window)
{
	m_window = window;
}

bool Renderer::init()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	FreeImage_Initialise();

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	glEnable(GL_FRAMEBUFFER_SRGB);
	checkGLError("Renderer initialization.");
	return true;
}

void Renderer::draw(Entity* entity)
{
	entity->draw();
	int err;
	if ((err = glGetError())) {
		std::cerr << "OpenGL error number " << err;
	}
}


Renderer::~Renderer()
{
}
