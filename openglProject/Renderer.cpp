#include "Renderer.h"



Renderer::Renderer(GLFWwindow* window)
{
	m_window = window;
}

bool Renderer::init()
{
	return true;
}

void Renderer::draw(Entity* entity, Camera* camera)
{
	entity->draw(camera);
}


Renderer::~Renderer()
{
}
