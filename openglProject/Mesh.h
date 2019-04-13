#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <vector>
#include "Face.h"
#include "Vertex.h"
#include "Material.h"
#include "Program.h"

class Mesh
{
public:
	Mesh(std::string name, std::vector<Vertex> vertices, std::vector<unsigned int> indices, Material* material);
	void init();
	void draw(Program* program);
	~Mesh();
private:
	GLuint m_vertexArrayObject;
	GLuint m_vertexBufferObject;
	GLuint m_elementBufferObject;
	std::string m_name;
	std::vector<Vertex> m_vertices;
	std::vector<unsigned int> m_indices;
	Material* m_material;
};

