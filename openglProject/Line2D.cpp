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

Line2D::Orientation Line2D::getOrientation(glm::vec2 p, glm::vec2 q, glm::vec2 r)
{

	float val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);

	if (val == 0.0f) return Orientation::COLLINEAR;  // colinear 

	return (val > 0.0f) ? Orientation::CLOCKWISE : Orientation::COUNTER_CLOCKWISE; // clock or counterclock wise 
}

bool Line2D::instersects(Line2D other)
{
	glm::vec2 p1 = getStartPoint();
	glm::vec2 q1 = getEndPoint();
	glm::vec2 p2 = other.getStartPoint();
	glm::vec2 q2 = other.getEndPoint();

	// Find the four orientations needed for general and 
// special cases 
	Line2D::Orientation o1 = getOrientation(p1, q1, p2);
	Line2D::Orientation o2 = getOrientation(p1, q1, q2);
	Line2D::Orientation o3 = getOrientation(p2, q2, p1);
	Line2D::Orientation o4 = getOrientation(p2, q2, q1);

	// General case 
	if (o1 != o2 && o3 != o4)
		return true;

	// Special Cases 
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1 
	if (o1 == Orientation::COLLINEAR && Line2D(p1, p2).isPointInside(q1))
		return true;

	// p1, q1 and q2 are colinear and q2 lies on segment p1q1 
	if (o2 == Orientation::COLLINEAR && Line2D(p1, q2).isPointInside(q1))
		return true;

	// p2, q2 and p1 are colinear and p1 lies on segment p2q2 
	if (o3 == Orientation::COLLINEAR && Line2D(p2, p1).isPointInside(q2))
		return true;

	// p2, q2 and q1 are colinear and q1 lies on segment p2q2 
	if (o4 == Orientation::COLLINEAR && Line2D(p2, q1).isPointInside(q2))
		return true;

	return false; // Doesn't fall in any of the above cases 
}

bool Line2D::isPoint()
{
	return m_startPoint == m_endPoint;
}


Line2D::~Line2D()
{
}

Shape::Type Line2D::getType()
{
	return LINE;
}

bool Line2D::isPointInside(glm::vec2 q)
{
	glm::vec2 p = getStartPoint();
	glm::vec2 r = getEndPoint();
	if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
		q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
		return true;

	return false;
}
