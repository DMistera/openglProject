#include "Mesh.h"

Mesh::Mesh(std::string name, std::vector<Vertex> vertices, std::vector<unsigned int> indices, Material* material)
{
	m_name = name;
	m_vertices = vertices;
	m_indices = indices;
	m_material = material;
}

void Mesh::init()
{
	glGenVertexArrays(1, &m_vertexArrayObject);
	glGenBuffers(1, &m_vertexBufferObject);
	glGenBuffers(1, &m_elementBufferObject);

	glBindVertexArray(m_vertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*m_vertices.size(), m_vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*m_indices.size(), m_indices.data(), GL_STATIC_DRAW);

	// 1st attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		4,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		sizeof(Vertex),                  // stride
		(void*)0            // array buffer offset
	);

	// 2nd attribute buffer : normals
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
	glVertexAttribPointer(
		1,                  // attribute 1
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		sizeof(Vertex),                  // stride
		(void*)offsetof(Vertex, normal)     // array buffer offset
	);

	// 3rd attribute buffer : textureCoords
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
	glVertexAttribPointer(
		2,                  // attribute 2
		2,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		sizeof(Vertex),                  // stride
		(void*)offsetof(Vertex, texCoord)           // array buffer offset
	);
	
	// 4th attribute buffer : vertexTangent
	glEnableVertexAttribArray(3);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
	glVertexAttribPointer(
		3,                  // attribute 3
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		sizeof(Vertex),                  // stride
		(void*)offsetof(Vertex, tangent)           // array buffer offset
	);
	
	glBindVertexArray(0);
}

void Mesh::use(Program* program)
{
	if (m_material != nullptr) {
		m_material->use(program);
	}
	glBindVertexArray(m_vertexArrayObject);
}

void Mesh::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
	glBindVertexArray(m_vertexArrayObject);
}

void Mesh::unbind()
{
	glBindVertexArray(0);
}

std::string Mesh::getName()
{
	return m_name;
}


void Mesh::draw(Program* program, GLenum mode, bool wires) {
	use(program);
	if (wires) {
		glDisable(GL_CULL_FACE);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	glDrawElements(mode, m_indices.size(), GL_UNSIGNED_INT, 0);
	if (wires) {
		glEnable(GL_CULL_FACE);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	unbind();
}

bool Mesh::operator==(Mesh* other)
{
	if (m_indices.size() != other->getIndices()->size()) {
		return false;
	}
	if (getMaterial()->diffuseMap->getPath() != other->getMaterial()->diffuseMap->getPath()) {
		return false;
	}
	return m_name == other->getName();
}

Material * Mesh::getMaterial()
{
	return m_material;
}

std::vector<Vertex>* Mesh::getBaseVertices()
{
	return &m_vertices;
}

std::vector<unsigned int>* Mesh::getIndices()
{
	return &m_indices;
}

Mesh::~Mesh()
{

	glBindVertexArray(m_vertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
	glDeleteBuffers(1, &m_vertexBufferObject);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBufferObject);
	glDeleteBuffers(1, &m_elementBufferObject);

	glDeleteVertexArrays(1, &m_vertexArrayObject);

	delete m_material;
}
