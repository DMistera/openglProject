#include "Mesh.h"

Mesh::Mesh(const char* path)
{
	m_path = path;
}

void Mesh::init()
{

	std::vector<glm::vec4> vertices;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> normals;

	std::ifstream in(m_path);
	std::string line;
	while (std::getline(in, line)) {
		if (line.substr(0, 2) == "v ") {
			//This is a vertex
			std::istringstream s(line.substr(2));
			glm::vec4 vertex;
			s >> vertex.x; s >> vertex.y; s >> vertex.z; s >> vertex.w;
			vertices.push_back(vertex);
		}
		else if (line.substr(0, 2) == "f ") {
			Face face = Face(line, &vertices, &texCoords, &normals);
			std::vector<glm::vec4> triangles = face.getTriangles();
			for (int i = 0; i < triangles.size(); i++) {
				m_vertices.push_back(triangles.at(i));
			}
		}
	}

	std::vector <GLfloat> bufferData;
	for (int i = 0; i < m_vertices.size(); i++) {
		glm::vec3 vertex = m_vertices.at(i);
		bufferData.push_back(vertex.x);
		bufferData.push_back(vertex.y);
		bufferData.push_back(vertex.z);
	}
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &m_vertexBuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*bufferData.size(), bufferData.data(), GL_STATIC_DRAW);
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
