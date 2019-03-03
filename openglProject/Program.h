#pragma once

#include <GL/glew.h>
#include "Shader.h"

class Program
{
public:
	Program();
	bool create(const char* vertexPath, const char* fragmentPath);
	~Program();
private:
	GLuint m_id;
};

