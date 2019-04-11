#pragma once

#include <glm/vec3.hpp>
#include <string>


class Material {
public:
	Material();
	void init();
	~Material();
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	float shininess;
	std::string name;
};