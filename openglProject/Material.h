#pragma once

#include <glm/vec3.hpp>
#include <string>
#include "Texture.h"
#include "Program.h"
#include <GL/glew.h>

class Material {
public:
	Material();
	~Material();
	void use(Program* p);
	glm::vec3 ambientColor;
	glm::vec3 diffuseColor;
	glm::vec3 specularColor;
	float shininess;
	std::string name;
	Texture* ambientMap;
	Texture* diffuseMap;
	Texture* specularMap;
	Texture* normalMap;
};