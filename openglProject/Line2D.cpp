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


Line2D::~Line2D()
{
}

Shape::Type Line2D::getType()
{
	return LINE;
}
