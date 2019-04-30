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
	Program(std::string vertexPath, std::string fragmentPath);
	bool init();
	void use();
	void setOnUse(std::function<void()> lambda);
	GLuint getLocation(const char* attributeName);
	std::string getVertexPath();
	std::string getFragmentPath();
	~Program();
	bool operator ==(Program other);
private:
	std::string m_vertexPath;
	std::string m_fragmentPath;
	GLuint m_id;
	std::function<void()> m_onUse;
};

