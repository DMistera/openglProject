#include "Player.h"


Player::Player()
{
	m_speed = 1.0f;
}

void Player::init(GLFWwindow* window)
{

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	m_camera = new Camera();
	m_camera->setPosition(glm::vec3(0.0f, 0.0f, -5.0f));
	m_camera->setNoseVector(glm::vec3(0.0f, 1.0f, 0.0f));

	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	m_startMousePos = glm::vec2(xpos, ypos);



	InputManager::setCursorPositionCallback([&](double xpos,double ypos) {
		float deltaY = m_startMousePos.y - ypos;
		float deltaX = m_startMousePos.x - xpos;
		m_camera->setRotation(glm::vec2(-deltaY / 100.0, deltaX / 100.0));
		//m_camera->setRotation(glm::vec2(1.0, 0.0));
	});

	InputManager::setKeyboardInputCallback([&](int key, int scancode, int action, int mods) {
		if (action == GLFW_PRESS) {
			if (key == GLFW_KEY_A) {
				m_velocity.x -= 5;
			}
			else if (key == GLFW_KEY_D) {
				m_velocity.x += 5;
			}
			else if (key == GLFW_KEY_S) {
				m_velocity.y -= 5;
			}
			else if (key == GLFW_KEY_W) {
				m_velocity.y += 5;
			}
		}
		else if (action == GLFW_RELEASE) {
			if (key == GLFW_KEY_A) {
				m_velocity.x += 5;
			}
			else if (key == GLFW_KEY_D) {
				m_velocity.x -= 5;
			}
			else if (key == GLFW_KEY_S) {
				m_velocity.y += 5;
			}
			else if (key == GLFW_KEY_W) {
				m_velocity.y -= 5;
			}
		}
	});
}

void Player::update(GLFWwindow* window, double deltaTime)
{
	m_camera->moveForward(m_velocity.y*m_speed*deltaTime);
	m_camera->moveSideways(m_velocity.x*m_speed*deltaTime);
	//m_camera->move((float)deltaTime*glm::vec3(m_velocity.x, 0.0f, m_velocity.y));
}


Camera * Player::getCamera()
{
	return m_camera;
}

Player::~Player()
{
}
