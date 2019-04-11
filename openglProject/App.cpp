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

	Model* monkeyMesh = m_resourceManager->getModel("monkey.obj");

	Model* cubeMesh = m_resourceManager->getModel("monkey.obj");

	Program* constant = m_resourceManager->getProgram("v_constant.glsl", "f_constant.glsl");


	m_sculpture = new BasicEntity(monkeyMesh);
	m_sculpture->init(m_resourceManager);

	m_lightEntity = new Entity();
	m_lightEntity->setToDraw(cubeMesh, constant);
	m_lightEntity->setScale(glm::vec3(0.1f, 0.1f, 0.1f));

	m_lightEntity2 = new Entity();
	m_lightEntity2->setToDraw(cubeMesh, constant);
	m_lightEntity2->setScale(glm::vec3(0.1f, 0.1f, 0.1f));

	m_lightSource = new LightSource(glm::vec3(), glm::vec3(0.8, 0.0, 0.2));
	m_sculpture->addLightSource(m_lightSource);

	m_lightSource2 = new LightSource(glm::vec3(), glm::vec3(0.2, 0.2, 0.0));
	m_sculpture->addLightSource(m_lightSource2);
}

double elapsed = 0;

void App::update(double time)
{
	elapsed += time;
	m_sculpture->setRotation(glm::vec3(0.0f, -elapsed, 0.0f));

	glm::vec3 lightPos = glm::vec3(2.0*sin(elapsed), 0.0f, 2.0*cos(elapsed));
	m_lightEntity->setPosition(lightPos);
	m_lightSource->setPosition(lightPos);

	glm::vec3 lightPos2 = glm::vec3(2.0*sin(elapsed/2), 0.0f, 2.0*cos(elapsed/2));
	m_lightEntity2->setPosition(lightPos2);
	m_lightSource2->setPosition(lightPos2);

	glm::vec3 viewPos = m_player->getCamera()->getPosition();
	m_player->update(m_window, time);
}

void App::draw(Renderer * renderer)
{
	renderer->draw(m_sculpture, m_player->getCamera());
	renderer->draw(m_lightEntity, m_player->getCamera());
	renderer->draw(m_lightEntity2, m_player->getCamera());
}
