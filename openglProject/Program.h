#pragma once

#include <GL/glew.h>
#include "Shader.h"
#include <iostream>
#include <functional>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Program
{
public:
	Program();
	bool create(const char* vertexPath, const char* fragmentPath);
	void use();
	void setUniformMat4(glm::mat4 value, const char* identifier);
	void setUniformVec4(glm::vec4 value, const char* identifier);
	void setUniformVec3(glm::vec3 value, const char* identifier);
	void setOnUse(std::function<void()> lambda);
	~Program();
private:
	GLuint m_id;
	std::function<void()> m_onUse;
};

