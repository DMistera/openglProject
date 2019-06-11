#include "Vertex.h"



Vertex::Vertex(glm::vec4 pos, glm::vec3 normal, glm::vec2 texCoord)
{
	position = pos;
	this->normal = normal;
	this->texCoord = texCoord;
	tangent = glm::vec3(1.0f, 0.0f, 0.0f);
}
