#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

class Vertex {
public:
	Vertex(glm::vec4 pos = glm::vec4(), glm::vec3 normal = glm::vec3() , glm::vec2 texCoord = glm::vec2());
	glm::vec4 position = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	glm::vec3 normal = glm::vec3(); 
	glm::vec2 texCoord = glm::vec2();
	glm::vec3 tangent = glm::vec3();
};