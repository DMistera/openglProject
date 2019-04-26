#include "Entity.h"



Entity::Entity()
{
	m_drawable = false;
}


Entity::~Entity()
{
}

void Entity::setToDraw(Model * m, Program* program)
{
	m_model = m;
	m_program = program;
	m_drawable = true;
}

void Entity::addEntity(Entity * e)
{
	m_entities.push_back(e);
}


void Entity::draw(Camera* camera)
{
	if (m_drawable) {
		m_program->use();
		setUniforms(camera);
		m_model->draw(m_program);
		glDisableVertexAttribArray(0);
	}

	for (int i = 0; i < m_entities.size(); i++) {
		m_entities.at(i)->draw(camera);
	}
}

Program * Entity::getProgram()
{
	return m_program;
}

void Entity::addLightSource(LightSource * lightSource)
{
	for (int i = 0; i < m_entities.size(); i++) {
		m_entities.at(i)->addLightSource(lightSource);
	}
}

void Entity::setUniforms(Camera * camera)
{
	glUniformMatrix4fv(m_program->getLocation("m_matrix"), 1, GL_FALSE, glm::value_ptr(getMatrix()));
	glUniformMatrix4fv(m_program->getLocation("p_matrix"), 1, GL_FALSE, glm::value_ptr(camera->getPerspectiveMatrix()));
	glUniformMatrix4fv(m_program->getLocation("v_matrix"), 1, GL_FALSE, glm::value_ptr(camera->getViewMatrix()));
	glUniform3fv(m_program->getLocation("viewPos"), 1, glm::value_ptr(camera->getPosition()));
}
