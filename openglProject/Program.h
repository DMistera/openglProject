#pragma once

#include <GL/glew.h>
#include "Shader.h"
#include <iostream>
#include <vector>

class Program
{
public:
	Program();
	bool create(const char* vertexPath, const char* fragmentPath);
	void use();
	~Program();
private:
	GLuint m_id;
};

