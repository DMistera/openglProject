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

	Program* constant = m_resourceManager->getProgram("v_constant.glsl", "f_constant.glsl");


	m_sculpture = new BasicEntity(monkeyMesh);
	m_sculpture->init(m_resourceManager);

	m_lightEntity = new Entity();
	m_lightEntity->setToDraw(cubeMesh, constant);
	m_lightEntity->setScale(glm::vec3(0.1f, 0.1f, 0.1f));

	m_lightSource = new LightSource(glm::vec3(), glm::vec3(1.0, 0.0, 1.0));
	m_sculpture->addLightSource(m_lightSource);
}

double elapsed = 0;

void App::update(double time)
{
	elapsed += time;
	//m_camera->setPosition(glm::vec3(5.0*cos(elapsed), 0.0f, 5.0*sin(elapsed)));
	m_sculpture->setRotation(glm::vec3(0.0f, -elapsed, 0.0f));

	glm::vec3 lightPos = glm::vec3(2.0*sin(elapsed), 0.0f, 2.0*cos(elapsed));
	m_lightEntity->setPosition(lightPos);
	m_lightSource->setPosition(lightPos);

	glm::vec3 viewPos = m_player->getCamera()->getPosition();
	m_player->update(m_window, time);
}

void App::draw(Renderer * renderer)
{
	renderer->draw(m_sculpture, m_player->getCamera());
	renderer->draw(m_lightEntity, m_player->getCamera());
}
