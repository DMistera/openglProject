#pragma once

#include <GLFW/glfw3.h>
#include <vector>
#include <functional>

class InputManager
{
public:
	static void init(GLFWwindow* window);
	static void setCursorPositionCallback(std::function<void(double, double)> f);
	InputManager();
	~InputManager();
private:
	static void m_cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
	static std::vector<std::function<void(double, double)>> m_cursorPositionCallbacks;
};

