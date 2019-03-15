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
	m_camera->setPosition(glm::vec3(0.0f, 0.0f, -5.0f));
	m_camera->setNoseVector(glm::vec3(0.0f, 1.0f, 0.0f));


	Mesh* cubeMesh = new Mesh("assets/cube.obj");
	cubeMesh->init();
	Program* program = new Program();
	program->create("basic.vertex", "basic.fragment");
	m_cube = new Entity();
	m_cube->setToDraw(cubeMesh, program);
}

float elapsed = 0;

void App::update(double time)
{
	elapsed += time;
	std::cout << time << std::endl;
	m_camera->setPosition(glm::vec3(0.0f, 0.0f, -5.0f - (2.0*sin(elapsed)) ));
}

void App::draw(Renderer * renderer)
{
	renderer->draw(m_cube, m_camera);
}
