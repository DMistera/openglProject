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
	glm::vec2 p = getPosition();
	glm::vec2 p2 = other.getPosition();
	float dist = MathUtils::distance(getPosition(), other.getPosition());
	std::cout << dist << std::endl;
	return getRadius() + other.getRadius() > dist;
}

bool Circle::intersects(Line2D line, glm::vec2* p1, glm::vec2* p2)
{
	glm::vec2 e = line.getStartPoint();
	glm::vec2 l = line.getEndPoint();
	glm::vec2 p = getPosition();
	float r = m_radius;

	glm::vec2 d = l - e;
	glm::vec2 f = e - p;

	//Quadratic equation
	float a = glm::dot(d, d);
	float b = 2.0f*glm::dot(f, d);
	float c = glm::dot(f, f) - r * r;

	float discriminant = b * b - 4 * a*c;
	if (discriminant >= 0) {
		discriminant = sqrt(discriminant);
		float t1 = (-b - discriminant) / (2 * a);
		float t2 = (-b + discriminant) / (2 * a);
		if (p1 != nullptr) {
			*p1 = line.getInterpolatedPoint(t1);
		}
		if (p2 != nullptr) {
			*p2 = line.getInterpolatedPoint(t2);
		}
		if (t1 >= 0 && t1 <= 1)
		{
			return true;
		}
		if (t2 >= 0 && t2 <= 1)
		{
			return true;
		}
	}
	return false;
}

bool Circle::intersects(Rectangle rect)
{
	std::vector<Line2D> lines = rect.getLines();
	for (int i = 0; i < lines.size(); i++) {
		if (intersects(lines[i])) {
			return true;
		}
	}
	//TODO Check if circle is not inside rectangle here;
	return false;
}

void Circle::resolve(Rectangle rect)
{
	struct LineToResolve {
		Line2D* line;
		float distance;
		bool taken;
	};
	std::vector<Line2D> lines = rect.getLines();
	std::vector<LineToResolve> rlines;
	for (int i = 0; i < lines.size(); i++) {
		if (intersects(lines[i])) {
			LineToResolve l;
			l.line = &lines[i];
			l.distance = distance(lines[i]);
			l.taken = false;
			rlines.push_back(l);
		}
	}
	for (int i = 0; i < rlines.size(); i++) {
		LineToResolve* lp = nullptr;
		float maxDist = 0;
		for (int j = 0; j < rlines.size(); j++) {
			LineToResolve& l = rlines[j];
			if (l.distance > maxDist && !l.taken) {
				maxDist = l.distance;
				lp = &l;
			}
		}
		lp->taken = true;
		resolve(*(lp->line));
	}
}


void Circle::resolve(Line2D line)
{
	glm::vec2 p1;
	glm::vec2 p2;
	if (intersects(line, &p1, &p2)) {
		glm::vec2 middle = (p1 + p2) / 2.0f;
		glm::vec2 dir = glm::normalize(getPosition() - middle);
		glm::vec2 center = middle + dir * m_radius;
		setPosition(center);
	}
}

float Circle::distance(Line2D line)
{
	return line.distanceToPoint(getPosition());
}

float Circle::getRadius()
{
	return getScale().x * m_radius;
}

Shape::Type Circle::getType()
{
	return CIRCLE;
}
