#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <vector>
#include "Face.h"
#include "Vertex.h"

class Mesh
{
public:
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
	void init();
	int getVertexCount();
	void draw();
	~Mesh();
private:
	GLuint m_vertexArrayObject;
	GLuint m_vertexBufferObject;
	GLuint m_elementBufferObject;
	

	std::vector<Vertex> m_vertices;
	std::vector<unsigned int> m_indices;
};

