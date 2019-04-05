#include "GameEngine.h"



GameEngine::GameEngine()
{

}


GameEngine::~GameEngine()
{
}

void GameEngine::init(GLFWwindow * window)
{
	m_window = window;
	m_resourceManager = new ResourceManager();
}
