#pragma once

#include <string>
#include <lodepng.h>
#include <GL/glew.h>
#include <iostream>
#include "EngineConstants.h"
#include "GLUtils.h"

class Texture
{
public:
	Texture(std::string path);
	void init(int textureUnit);
	~Texture();
	bool operator ==(Texture another);
	std::string getPath();
	void bind();
private:
	int findPower(int x);
	GLuint m_id;
	std::string m_path;
};

