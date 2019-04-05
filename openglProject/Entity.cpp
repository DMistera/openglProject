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
	setUniforms(camera);

	m_mesh->useVertexBuffer();
	glDrawArrays(GL_TRIANGLES, 0, m_mesh->getVertexCount());
	glDisableVertexAttribArray(0);
}

Program * Entity::getProgram()
{
	return m_program;
}

void Entity::setUniforms(Camera * camera)
{
	glUniformMatrix4fv(m_program->getLocation("m_matrix"), 1, GL_FALSE, glm::value_ptr(getMatrix()));
	glUniformMatrix4fv(m_program->getLocation("p_matrix"), 1, GL_FALSE, glm::value_ptr(camera->getPerspectiveMatrix()));
	glUniformMatrix4fv(m_program->getLocation("v_matrix"), 1, GL_FALSE, glm::value_ptr(camera->getViewMatrix()));
	glUniform3fv(m_program->getLocation("viewPos"), 1, glm::value_ptr(camera->getPosition()));
}
