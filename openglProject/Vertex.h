#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

struct Vertex {
	glm::vec4 position;
	glm::vec3 normal;
	glm::vec2 texCoord;
	glm::vec3 tangent;
};