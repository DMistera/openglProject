#include "Player.h"


Player::Player()
{
	m_speed = 2.0f;
}

void Player::init(GLFWwindow* window)
{

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	m_camera = new Camera();
	m_camera->setPosition(glm::vec3(0.0f, playerHeight, 0.0f));
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
				m_velocity.x -= m_speed;
			}
			else if (key == GLFW_KEY_D) {
				m_velocity.x += m_speed;
			}
			else if (key == GLFW_KEY_S) {
				m_velocity.z += m_speed;
			}
			else if (key == GLFW_KEY_W) {
				m_velocity.z -= m_speed;
			}
			else if (key == GLFW_KEY_SPACE) {
				if (m_canJump) {
					m_velocity.y = 0.04f;
					m_canJump = false;
				}
			}
		}
		else if (action == GLFW_RELEASE) {
			if (key == GLFW_KEY_A) {
				m_velocity.x += m_speed;
			}
			else if (key == GLFW_KEY_D) {
				m_velocity.x -= m_speed;
			}
			else if (key == GLFW_KEY_S) {
				m_velocity.z -= m_speed;
			}
			else if (key == GLFW_KEY_W) {
				m_velocity.z += m_speed;
			}
		}
	});

	m_hitbox.setOnResolveY([&]() -> void {
		m_velocity.y = 0.0f;
		m_canJump = true;
	});
}

void Player::update(double deltaTime)
{
	m_velocity.y += deltaTime * gravityAcceleration;


	m_camera->moveForward(-m_velocity.z*deltaTime);
	m_camera->moveSideways(m_velocity.x*deltaTime);
	m_camera->move(glm::vec3(0.0f, m_velocity.y, 0.0f));
	updateHitboxPosiiton(m_camera);

}

void Player::resolveHitbox(Chamber * currentChamber)
{
	if (m_hitbox.collide(currentChamber->getHitbox())) {
		m_hitbox.resolve(currentChamber->getHitbox());
		glm::vec3 hbpos = m_hitbox.getGlobalPosition();
		m_camera->moveTo(glm::vec3(hbpos.x, hbpos.y + playerHeight, hbpos.z));
	}
	m_lightSource->setPosition(m_camera->getPosition());
}




Camera * Player::getCamera()
{
	return m_camera;
}

LightSource * Player::getLightSource()
{
	return m_lightSource;
}

PrismHitbox * Player::getHitbox()
{
	return &m_hitbox;
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
	m_hitbox.setPosition(glm::vec3(camPos.x, camPos.y - playerHeight, camPos.z));
}
