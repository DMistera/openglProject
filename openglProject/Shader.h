#pragma once

#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	Shader();
	bool init(std::string path, GLenum type);
	GLuint getID();
	~Shader();
private:
	GLuint m_id;
};

