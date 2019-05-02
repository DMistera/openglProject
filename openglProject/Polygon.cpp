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
	glm::mat4 matrix = getMatrix();
	for (glm::vec2 v : vertices) {
		glm::vec2 transformed = matrix * glm::vec4(v, 0.0, 1.0);
		result.push_back(transformed);
	}
	return result;
}
