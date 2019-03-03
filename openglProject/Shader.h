#pragma once

#include <GL/glew.h>
#include <fstream>
#include <sstream>

class Shader
{
public:
	Shader();
	bool init(const char* path);
	GLuint getID();
	~Shader();
private:
	GLuint m_id;
};

