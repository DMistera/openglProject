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
	glm::mat4 matrix = *getMatrix();
	for (glm::vec2 v : vertices) {
		glm::vec2 transformed = matrix * glm::vec4(v, 0.0, 1.0);
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

Shape::Type Polygon::getType()
{
	return POLYGON;
}
