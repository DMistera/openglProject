#include "EntityInstancer.h"



EntityInstancer::EntityInstancer(Entity* entity) : Instancer(entity)
{
}


EntityInstancer::~EntityInstancer()
{
}

void EntityInstancer::setUniforms(Entity * sample)
{
	sample->setUniforms();
}

bool EntityInstancer::inSameInstanceGroup(Entity *, Entity *)
{
	return true;
}

void EntityInstancer::setInstancedVertexAttributes(std::vector<Entity*> entities)
{
	std::vector<glm::mat4> modelMatrices;
	for (Entity* e : entities) {
		modelMatrices.push_back(*e->getMatrix());
	}

	glGenBuffers(1, &m_modelMatrixBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_modelMatrixBuffer);
	glBufferData(GL_ARRAY_BUFFER, modelMatrices.size() * sizeof(glm::mat4), modelMatrices.data(), GL_STATIC_DRAW);
	GLsizei v4Size = sizeof(glm::vec4);
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 4 * v4Size, (void*)0);
	glEnableVertexAttribArray(5);
	glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, 4 * v4Size, (void*)(v4Size));
	glEnableVertexAttribArray(6);
	glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, 4 * v4Size, (void*)(2 * v4Size));
	glEnableVertexAttribArray(7);
	glVertexAttribPointer(7, 4, GL_FLOAT, GL_FALSE, 4 * v4Size, (void*)(3 * v4Size));
	glVertexAttribDivisor(4, 1);
	glVertexAttribDivisor(5, 1);
	glVertexAttribDivisor(6, 1);
	glVertexAttribDivisor(7, 1);
}

void EntityInstancer::cleanUp()
{
	glDeleteBuffers(1, &m_modelMatrixBuffer);
}

void EntityInstancer::init()
{
	Instancer::init();
}
