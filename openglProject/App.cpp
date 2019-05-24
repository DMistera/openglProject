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
	m_map->generate(m_resourceManager, m_player->getCamera());

	m_map->addLightSource(m_player->getLightSource());

	m_instancer = new EntityInstancer(m_map);
	m_instancer->init();
}

double elapsed = 0;

void App::update(double time)
{
	elapsed += time;

	m_player->update(m_window, time, m_map->getActiveChamber());
	m_map->checkActiveChamberChange(m_player);
}

void App::draw(Renderer * renderer)
{
	m_instancer->draw();
	//renderer->draw(m_map);
	m_map->getActiveChamber()->getHitbox()->draw(m_resourceManager, m_player->getCamera());
	for (Chamber* adj : m_map->getActiveChamber()->getAdjacentChambers()) {
		adj->getDoorFrameHitboxes()->draw(m_resourceManager, m_player->getCamera());
	}
}
