#pragma once

#include <string>
#include <GL/glew.h>
#include <iostream>
#include "EngineConstants.h"
#include "GLUtils.h"
#include <FreeImage.h>

class Texture
{
public:
	Texture(std::string path);
	void init(int textureUnit, bool gemmaCorrelation);
	~Texture();
	bool operator ==(Texture another);
	std::string getPath();
	void bind();
private:
	GLuint m_id;
	std::string m_path;
};

