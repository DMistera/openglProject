#pragma once

#include <GLFW/glfw3.h>
#include <vector>
#include <functional>

class InputManager
{
public:
	static void init(GLFWwindow* window);
	static void setCursorPositionCallback(std::function<void(double, double)> f);
	static void setKeyboardInputCallback(std::function<void(int key, int scancode, int action, int mods)> f);
	InputManager();
	~InputManager();
private:
	static void m_cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
	static void m_keyboardInputCallback(GLFWwindow* window, int key,  int scancode, int action, int mods);
	static std::vector<std::function<void(double, double)>> m_cursorPositionCallbacks;
	static std::vector<std::function<void(int key, int scancode, int action, int mods)>> m_keyboardInputCallbacks;
};

