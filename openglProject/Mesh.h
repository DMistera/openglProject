#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Face.h"

#pragma once
class Mesh
{
public:
	Mesh(const char* path);
	void init();
	void useVertexBuffer();
	std::vector<glm::vec4> getVertices();
	~Mesh();
private:
	const char* m_path;
	GLuint m_vertexBuffer;
	//Array of vertices
	std::vector<glm::vec4> m_vertices;
};

