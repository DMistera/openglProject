#pragma once

#include <GL/glew.h>
#include "Shader.h"
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Program
{
public:
	Program();
	bool create(const char* vertexPath, const char* fragmentPath);
	void use();
	void setUniform(glm::mat4 value, const char* identifier);
	~Program();
private:
	GLuint m_id;
};

