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
	Mesh(std::string path);
	void init();
	void useVertexBuffer();
	int getVertexCount();
	std::string getPath();
	~Mesh();
private:
	std::string m_objPath;
	std::string m_mtlPath;
	GLuint m_vertexBuffer;
	GLuint m_normalBuffer;
	//Array of vertices
	std::vector<Face> m_faces;
	float* m_bufferDataArray;
	int m_vertexCount;
};

