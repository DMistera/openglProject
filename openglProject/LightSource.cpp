#include "LightSource.h"

LightSource::LightSource(glm::vec3 position, glm::vec3 color)
{
	m_position = position;
	m_ambientColor = color;
	m_diffuseColor = color;
	m_specularColor = color;
	m_constant = 0.0f;
	m_linear = 0.0f;
	m_quadratic = 20.0f;
}

glm::vec3 LightSource::getAmbientColor()
{
	return m_ambientColor;
}

glm::vec3 LightSource::getDiffuseColor()
{
	return m_diffuseColor;
}

glm::vec3 LightSource::getSpecularColor()
{
	return m_specularColor;
}

glm::vec3 LightSource::getPosition()
{
	return m_position;
}

float LightSource::getConstant()
{
	return m_constant;
}

float LightSource::getLinear()
{
	return m_linear;
}

float LightSource::getQuadratic()
{
	return m_quadratic;
}

void LightSource::setPosition(glm::vec3 position)
{
	m_position = position;
}
