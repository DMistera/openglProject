#include "InputManager.h"

std::vector<std::function<void(double, double)>> InputManager::m_cursorPositionCallbacks;
std::vector<std::function<void(int key, int scancode, int action, int mods)>> InputManager::m_keyboardInputCallbacks;

void InputManager::init(GLFWwindow * window)
{
	glfwSetCursorPosCallback(window, m_cursorPositionCallback);
	glfwSetKeyCallback(window, m_keyboardInputCallback);
}

void InputManager::setCursorPositionCallback(std::function<void(double, double)> f)
{
	m_cursorPositionCallbacks.push_back(f);
}

void InputManager::setKeyboardInputCallback(std::function<void(int key, int scancode, int action, int mods)> f)
{
	m_keyboardInputCallbacks.push_back(f);
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

void InputManager::m_keyboardInputCallback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	for (int i = 0; i < m_keyboardInputCallbacks.size(); i++) {
		(m_keyboardInputCallbacks.at(i))(key, scancode, action, mods);
	}
}
