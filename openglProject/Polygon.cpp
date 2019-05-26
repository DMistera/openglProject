#include "Polygon.h"



Polygon::Polygon()
{
}


Polygon::~Polygon()
{
}

std::vector<glm::vec2> Polygon::getVertices()
{
	std::vector<glm::vec2> vertices = getBaseVertices();
	std::vector<glm::vec2> result;
	for (glm::vec2 v : vertices) {
		glm::vec2 transformed = applyTransformation(v);
		result.push_back(transformed);
	}
	return result;
}

std::vector<Line2D> Polygon::getLines()
{
	std::vector<glm::vec2> vertices = getVertices();
	std::vector<Line2D> lines;
	for (int i = 0; i < vertices.size() - 1; i++) {
		lines.push_back(Line2D(vertices[i], vertices[i + 1]));
	}
	lines.push_back(Line2D(vertices[vertices.size() - 1], vertices[0]));
	return lines;
}

bool Polygon::isPointInside(glm::vec2 point)
{
	//From stack overflow
	std::vector<glm::vec2> vertices = getVertices();
	int i, j = 0;
	bool c = false;
	int nvert = vertices.size();
	for (i = 0, j = nvert - 1; i < nvert; j = i++) {
		if (((vertices[i].y > point.y) != (vertices[j].y > point.y)) &&
			(point.x < (vertices[j].x - vertices[i].x) * (point.y - vertices[i].y) / (vertices[j].y - vertices[i].y) + vertices[i].x))
			c = !c;
	}
	return c;
}

Shape::Type Polygon::getType()
{
	return POLYGON;
}
