#include "App.h"



App::App()
{
}


App::~App()
{
}

void App::start()
{
	m_player = new Player();
	m_player->init(m_window);

	Mesh* monkeyMesh = new Mesh("assets/monkey.obj");
	monkeyMesh->init();

	Mesh* cubeMesh = new Mesh("assets/cube.obj");
	cubeMesh->init();

	Program* basic = new Program();
	basic->create("v_basic.glsl", "f_basic.glsl");

	Program* constant = new Program();
	constant->create("v_constant.glsl", "f_constant.glsl");


	m_sculpture = new Entity();
	m_sculpture->setToDraw(monkeyMesh, basic);

	m_lightSource = new Entity();
	m_lightSource->setToDraw(cubeMesh, constant);
	m_lightSource->setScale(glm::vec3(0.1f, 0.1f, 0.1f));
}

double elapsed = 0;

void App::update(double time)
{
	elapsed += time;
	//m_camera->setPosition(glm::vec3(5.0*cos(elapsed), 0.0f, 5.0*sin(elapsed)));
	m_sculpture->setRotation(glm::vec3(0.0f, -elapsed, 0.0f));

	glm::vec3 lightPos = glm::vec3(2.0*sin(elapsed), 0.0f, 2.0*cos(elapsed));
	m_lightSource->setPosition(lightPos);
	glm::vec3 viewPos = m_player->getCamera()->getPosition();
	m_sculpture->getProgram()->setOnUse([=]() {
		m_sculpture->getProgram()->setUniformVec3(lightPos, "lightPos");
		m_sculpture->getProgram()->setUniformVec3(viewPos, "viewPos");
	});


	m_player->update(m_window, time);
}

void App::draw(Renderer * renderer)
{
	renderer->draw(m_sculpture, m_player->getCamera());
	renderer->draw(m_lightSource, m_player->getCamera());
}
