#include "Line2D.h"



Line2D::Line2D(glm::vec2 start, glm::vec2 end)
{
	m_startPoint = start;
	m_endPoint = end;
}

glm::vec2 Line2D::getStartPoint()
{
	return m_startPoint;
}

glm::vec2 Line2D::getEndPoint()
{
	return m_endPoint;
}

glm::vec2 Line2D::getInterpolatedPoint(float t)
{
	float x = (m_endPoint.x - m_startPoint.x) * t + m_startPoint.x;
	float y = (m_endPoint.y - m_startPoint.y) * t + m_startPoint.y;
	return glm::vec2(x, y);
}

void Line2D::getEquation(float * a, float * b)
{
	float diffX = (m_endPoint.x - m_startPoint.x);
	float diffY = (m_endPoint.y - m_startPoint.y);
	*a = diffY / diffX;
	*b = m_startPoint.y - (*a)*m_startPoint.y;
}

float Line2D::distanceToPoint(glm::vec2 point)
{
	float x0 = point.x;
	float y0 = point.y;
	float x1 = getStartPoint().x;
	float y1 = getStartPoint().y;
	float x2 = getEndPoint().x;
	float y2 = getEndPoint().y;
	//Formula from WIkipedia
	float u = abs((y2 - y1)*x0 - (x2 - x1)*y0 + x2 * y1 - y2 * x1);
	float b = sqrt(pow(y2 - y1, 2.0) + pow(x2 - x1, 2.0));
	return u/b;
}


Line2D::~Line2D()
{
}

Shape::Type Line2D::getType()
{
	return LINE;
}
