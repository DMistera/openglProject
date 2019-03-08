#include <GL/glew.h>
#include <glm/glm.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#pragma once
class Mesh
{
public:
	Mesh(const char* path);
	void init();
	~Mesh();
private:
	const char* m_path;
	//Array of vertices
	glm::vec4* m_vertices;
};

