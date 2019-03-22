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
			s >> vertex.x; s >> vertex.y; s >> vertex.z;
			if (!s.eof()) {
				s >> vertex.w;
			}
			else {
				vertex.w = 1.0;
			}
			vertices.push_back(vertex);
		}
		else if (line.substr(0, 3) == "vn ") {
			//This is a normal
			std::istringstream s(line.substr(3));
			glm::vec3 vertex;
			s >> vertex.x; s >> vertex.y; s >> vertex.z;
			normals.push_back(vertex);
		}
		else if (line.substr(0, 2) == "f ") {
			Face face = Face(line, &vertices, &texCoords, &normals);
			m_faces.push_back(face);
		}
	}

	m_vertexCount = 0;
	std::vector <GLfloat> vertexBufferData; //vec4
	std::vector <GLfloat> normalBufferData; //vec3
	for (int j = 0; j < m_faces.size(); j++) {
		Face face = m_faces.at(j);
		std::vector<glm::vec4> triangles = face.getTriangles();
		glm::vec3 normal = face.getNormal();
		m_vertexCount += triangles.size();
		for (int i = 0; i < triangles.size(); i++) {
			glm::vec4 vertex = triangles.at(i);
			vertexBufferData.push_back(vertex.x);
			vertexBufferData.push_back(vertex.y);
			vertexBufferData.push_back(vertex.z);
			vertexBufferData.push_back(vertex.w);
			
			normalBufferData.push_back(normal.x);
			normalBufferData.push_back(normal.y);
			normalBufferData.push_back(normal.z);
		}
	}
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &m_vertexBuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vertexBufferData.size(), vertexBufferData.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &m_normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*normalBufferData.size(), normalBufferData.data(), GL_STATIC_DRAW);
}

void Mesh::useVertexBuffer()
{
	// 1st attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		4,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	// 2nd attribute buffer : normals
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, m_normalBuffer);
	glVertexAttribPointer(
		1,                  // attribute 1
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
}


int Mesh::getVertexCount()
{
	return m_vertexCount;
}

Mesh::~Mesh()
{
}
