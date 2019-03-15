#include "Mesh.h"

Mesh::Mesh(const char* path)
{
	m_path = path;
}

void Mesh::init()
{

	std::ifstream in(m_path);
	std::string line;
	while (std::getline(in, line)) {
		if (line.substr(0, 2) == "v ") {
			//This is a vertex
			std::istringstream s(line.substr(2));
			glm::vec4 vertex;
			s >> vertex.x; s >> vertex.y; s >> vertex.z; s >> vertex.w;
			m_vertices.push_back(vertex);
		}
	}

	GLuint vertexArrayID = 0;
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	GLfloat* bufferData = new GLfloat[m_vertices.size() * 3];
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &m_vertexBuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(bufferData), bufferData, GL_STATIC_DRAW);
}

void Mesh::useVertexBuffer()
{
	// 1st attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
}

std::vector<glm::vec4> Mesh::getVertices()
{
	return m_vertices;
}


Mesh::~Mesh()
{
}
