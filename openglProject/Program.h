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
	Program(const char* vertexPath, const char* fragmentPath);
	bool init();
	void use();
	void setOnUse(std::function<void()> lambda);
	GLuint getLocation(const char* attributeName);
	const char* getVertexPath();
	const char* getFragmentPath();
	~Program();
private:
	const char* m_vertexPath;
	const char* m_fragmentPath;
	GLuint m_id;
	std::function<void()> m_onUse;
};

