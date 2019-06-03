#include "Rectangle.h"




Rectangle::Rectangle(float width, float heigth)
{
	m_width = width;
	m_height = heigth;
}

Rectangle::Rectangle(glm::vec2 a, glm::vec2 b)
{
	m_width = abs(a.x - b.x);
	m_height = abs(a.y - b.y);
	glm::vec2 middle = glm::vec2((a.x + b.x) / 2.0f, (a.y + b.y) / 2.0f);
	setPosition(middle);
}

Rectangle::~Rectangle()
{
}

bool Rectangle::intersects(Rectangle other)
{
	std::vector<Line2D> lines = getLines();
	std::vector<Line2D> lines2 = other.getLines();
	for (Line2D l : lines) {
		for (Line2D l2 : lines2) {
			if (l.instersects(l2)) {
				return true;
			}
		}
	}
	if (isPointInside(other.getCentre())) {
		return true;
	}
	if (other.isPointInside(getCentre())) {
		return true;
	}
	return false;
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

Shape::Type Rectangle::getType()
{
	return RECTANGLE;
}
