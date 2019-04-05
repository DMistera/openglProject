#pragma once

#include <glm/vec3.hpp>

class LightSource {
public:
	LightSource(glm::vec3 position, glm::vec3 color);
	glm::vec3 getAmbientColor();
	glm::vec3 getDiffuseColor();
	glm::vec3 getSpecularColor();
	glm::vec3 getPosition();
	float getConstant();
	float getLinear();
	float getQuadratic();
	void setPosition(glm::vec3 position);
private:
	glm::vec3 m_position;

	float m_constant;
	float m_linear;
	float m_quadratic;

	glm::vec3 m_ambientColor;
	glm::vec3 m_diffuseColor;
	glm::vec3 m_specularColor;
};