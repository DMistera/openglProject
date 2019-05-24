#include "Entity.h"



Entity::Entity()
{
	m_drawable = false;
}


Entity::~Entity()
{
	for (auto e : m_entities) {
		delete e;
	}
	m_entities.clear();
}

void Entity::setToDraw(Model * m, Program* program, Camera* camera)
{
	m_model = m;
	m_program = program;
	m_camera = camera;
	m_drawable = true;
}

void Entity::addEntity(Entity * e)
{
	m_entities.push_back(e);
}


void Entity::draw()
{
	if (m_drawable) {
		m_program->use();
		setInstanceUniforms();
		setUniforms();
		m_model->draw(m_program);
		glDisableVertexAttribArray(0);
	}

	for (int i = 0; i < m_entities.size(); i++) {
		m_entities.at(i)->draw();
	}
}

Program * Entity::getProgram()
{
	return m_program;
}

Model * Entity::getModel()
{
	return m_model;
}

Camera * Entity::getCamera()
{
	return m_camera;
}

std::vector<Entity*> Entity::getEntities()
{
	return m_entities;
}

bool Entity::isDrawable()
{
	return m_drawable;
}

void Entity::addLightSource(LightSource * lightSource)
{
	for (int i = 0; i < m_entities.size(); i++) {
		m_entities.at(i)->addLightSource(lightSource);
	}
}

void Entity::setUniforms()
{
	glUniformMatrix4fv(m_program->getLocation("p_matrix"), 1, GL_FALSE, glm::value_ptr(m_camera->getPerspectiveMatrix()));
	glUniformMatrix4fv(m_program->getLocation("v_matrix"), 1, GL_FALSE, glm::value_ptr(m_camera->getViewMatrix()));
	glUniform3fv(m_program->getLocation("viewPos"), 1, glm::value_ptr(m_camera->getPosition()));
}

void Entity::setInstanceUniforms()
{
	glUniformMatrix4fv(m_program->getLocation("m_matrix"), 1, GL_FALSE, glm::value_ptr(*getMatrix()));
}
