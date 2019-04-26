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

	m_map = new Map();
	m_map->generate(m_resourceManager);

	m_map->addLightSource(m_player->getLightSource());
}

double elapsed = 0;

void App::update(double time)
{
	elapsed += time;

	m_player->update(m_window, time);
}

void App::draw(Renderer * renderer)
{
	renderer->draw(m_map, m_player->getCamera());
}
