#include "Rectangle.h"



Rectangle::Rectangle()
{
}


Rectangle::~Rectangle()
{
}

std::vector<glm::vec2> Rectangle::getBaseVertices()
{
	float dx = m_width / 2.0f;
	float dy = m_height / 2.0f;
	std::vector<glm::vec2> result;
	result.push_back(glm::vec2(dx, dy));
	result.push_back(glm::vec2(dx, -dy));
	result.push_back(glm::vec2(-dx, -dy));
	result.push_back(glm::vec2(-dx, dy));
	return result;
}
