#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::setToDraw(Mesh * m, Program* program)
{
	m_mesh = m;
	m_program = program;
}

void Entity::addEntity(Entity * e)
{
	m_entities.push_back(e);
}

void Entity::draw(Camera* camera)
{
	m_program->use();
	m_program->setUniformMat4(getMatrix(), "m_matrix");
	m_program->setUniformMat4(camera->getPerspectiveMatrix(), "p_matrix");
	m_program->setUniformMat4(camera->getViewMatrix(), "v_matrix");

	glm::vec4 lightPosition = glm::vec4(2.0f, 0.0f, 0.0f, 1.0f);

	m_mesh->useVertexBuffer();
	glDrawArrays(GL_TRIANGLES, 0, m_mesh->getVertexCount());
	glDisableVertexAttribArray(0);
}

Program * Entity::getProgram()
{
	return m_program;
}
