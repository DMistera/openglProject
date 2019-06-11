#include "App.h"



App::App()
{
	m_showHitboxes = false;
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

	InputManager::setKeyboardInputCallback([&](int key, int scancode, int action, int mods) {
		if (key == GLFW_KEY_H && action == GLFW_PRESS) {
			m_showHitboxes = !m_showHitboxes;
		}
	});
}

double elapsed = 0;

void App::update(double time)
{
	elapsed += time;

	Chamber* activeChamber = m_map->getActiveChamber();
	m_player->update(time, activeChamber);
	m_map->checkActiveChamberChange(m_player);
	m_player->resolveHitbox(activeChamber);
	m_map->updateAll(time);
}

void App::draw(Renderer * renderer)
{
	m_instancer->draw();


	//renderer->draw(m_map);
	if (m_showHitboxes) {
		m_map->getActiveChamber()->getHitbox()->draw(m_resourceManager, m_player->getCamera());
		for (Chamber* adj : m_map->getActiveChamber()->getAdjacentChambers()) {
			adj->getDoorFrameHitbox()->draw(m_resourceManager, m_player->getCamera());
		}
	}
}
