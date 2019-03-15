#include "App.h"



App::App()
{
}


App::~App()
{
}

void App::start()
{
	m_camera = new Camera();
	m_camera->setPosition(glm::vec3(-1, 0, 0));


	Mesh* cubeMesh = new Mesh("assets/cube.obj");
	Program* program = new Program();
	program->create("basic.vertex", "basic.fragment");
	cubeMesh->init();
	m_cube = new Entity();
	m_cube->setToDraw(cubeMesh, program);
}

void App::update(int time)
{

}

void App::draw(Renderer * renderer)
{
	renderer->draw(m_cube, m_camera);
}
