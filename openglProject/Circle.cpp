#include "Circle.h"



Circle::Circle(float radius)
{
	m_radius = radius;
}


Circle::~Circle()
{
}

bool Circle::intersects(Circle other)
{
	float dist = MathUtils::distance(getGlobalPosition(), other.getGlobalPosition());
	std::cout << dist << std::endl;
	return getRadius() + other.getRadius() > dist;
}

bool Circle::intersects(Line2D line)
{
	glm::vec2 e = line.getStartPoint();
	glm::vec2 l = line.getEndPoint();
	glm::vec2 p = m_position;
	float r = m_radius;

	glm::vec2 d = l - e;
	glm::vec2 f = e - p;

	//Quadratic equation
	float a = glm::dot(d, d);
	float b = 2.0f*glm::dot(f, d);
	float c = glm::dot(f, f) - r * r;

	float discriminant = b * b - 4 * a*c;
	return discriminant >= 0;
}

bool Circle::intersects(Rectangle rect)
{
	return false;
}

float Circle::getRadius()
{
	return getScaleV2().x * m_radius;
}

Shape::Type Circle::getType()
{
	return CIRCLE;
}
