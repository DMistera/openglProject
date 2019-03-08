#include "Mesh.h"

Mesh::Mesh(const char* path)
{
}

void Mesh::init()
{

	std::vector<glm::vec4> vertices;

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
	}

	m_vertices = vertices.data();
}


Mesh::~Mesh()
{
}
