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
	std::vector<Face> getFaces();
	int getVertexCount();
	~Mesh();
private:
	const char* m_path;
	GLuint m_vertexBuffer;
	GLuint m_normalBuffer;
	//Array of vertices
	std::vector<Face> m_faces;
	float* m_bufferDataArray;
	int m_vertexCount;
};

