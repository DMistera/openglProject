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
	m_program->setUniform(getMatrix(), "m_matrix");
	m_program->setUniform(camera->getPerspectiveMatrix(), "p_matrix");
	m_program->setUniform(camera->getViewMatrix(), "v_matrix");

	m_mesh->useVertexBuffer();
	glDrawArrays(GL_TRIANGLES, 0, m_mesh->getVertexCount());
	glDisableVertexAttribArray(0);
}
