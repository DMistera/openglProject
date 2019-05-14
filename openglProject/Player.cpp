#include "Player.h"


Player::Player()
{
	m_speed = 0.4f;
}

void Player::init(GLFWwindow* window)
{

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	m_camera = new Camera();
	m_camera->setPosition(glm::vec3(0.0f, 1.0f, 0.0f));
	m_camera->setNoseVector(glm::vec3(0.0f, 1.0f, 0.0f));
	m_camera->setRotation(glm::vec2(0.0f, 0.0f));

	m_lightSource = new LightSource(m_camera->getPosition(), glm::vec3(1.0, 1.0, 0.0));

	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	m_mousePos = glm::vec2(xpos, ypos);
	m_cameraAngle = glm::vec2(0.0f);


	InputManager::setCursorPositionCallback([&](double xpos,double ypos) {
		m_cameraAngle.x += (m_mousePos.x - xpos)*m_cameraSpeed;
		m_cameraAngle.y += (m_mousePos.y - ypos)*m_cameraSpeed;
		m_mousePos = glm::vec2(xpos, ypos);
		float upThreshold = M_PI / 2.0 - 0.00001;
		float bottomThreshold = -M_PI / 2.0 + 0.000001;
		if (m_cameraAngle.y > upThreshold) {
			m_cameraAngle.y = upThreshold;
		}
		else if (m_cameraAngle.y < bottomThreshold) {
			m_cameraAngle.y = bottomThreshold;
		}
		m_camera->setRotation(m_cameraAngle);
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

void Player::update(GLFWwindow* window, double deltaTime, Chamber* chamber)
{

	Camera cameraCopy = *m_camera;
	cameraCopy.moveForward(m_velocity.y*m_speed*deltaTime);
	cameraCopy.moveSideways(m_velocity.x*m_speed*deltaTime);
	updateHitboxPosiiton(&cameraCopy);

	if (m_hitbox.collide(chamber->getHitbox())) {
		std::cout << "Collision!" << std::endl;
		updateHitboxPosiiton(m_camera);
	}
	else {
		m_camera->moveForward(m_velocity.y*m_speed*deltaTime);
		m_camera->moveSideways(m_velocity.x*m_speed*deltaTime);
		m_lightSource->setPosition(m_camera->getPosition());
	}
	m_hitbox.getBase()->updateMatrix();
}


Camera * Player::getCamera()
{
	return m_camera;
}

LightSource * Player::getLightSource()
{
	return m_lightSource;
}

Player::~Player()
{
}

glm::vec3 Player::getShiftVector(double deltaTime)
{
	glm::vec2 shift = m_velocity * m_speed * (float)deltaTime;
	return glm::vec3(shift.x, 0, -shift.y);
}

void Player::updateHitboxPosiiton(Camera * cam)
{
	glm::vec3 camPos = cam->getPosition();
	m_hitbox.getBase()->setPosition(glm::vec2(camPos.x, camPos.z));
}
