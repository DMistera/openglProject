#include "InputManager.h"

std::vector<std::function<void(double, double)>> InputManager::m_cursorPositionCallbacks;

void InputManager::init(GLFWwindow * window)
{
	glfwSetCursorPosCallback(window, m_cursorPositionCallback);
}

void InputManager::setCursorPositionCallback(std::function<void(double, double)> f)
{
	m_cursorPositionCallbacks.push_back(f);
}

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::m_cursorPositionCallback(GLFWwindow * window, double xpos, double ypos)
{
	for (int i = 0; i < m_cursorPositionCallbacks.size(); i++) {
		(m_cursorPositionCallbacks.at(i))(xpos, ypos);
	}
}
