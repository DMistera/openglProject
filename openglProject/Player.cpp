#include "Player.h"


Player::Player()
{
}

void Player::init(GLFWwindow* window)
{

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwGetCursorPos(window, &m_cxPos,& m_cyPos);

	m_camera = new Camera();
	m_camera->setPosition(glm::vec3(0.0f, 0.0f, -5.0f));
	m_camera->setNoseVector(glm::vec3(0.0f, 1.0f, 0.0f));
}

void Player::update(GLFWwindow* window, double deltaTime)
{
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	m_camera->setRotation(glm::vec2(ypos/100.0, xpos/100.0));
}


Camera * Player::getCamera()
{
	return m_camera;
}

Player::~Player()
{
}
