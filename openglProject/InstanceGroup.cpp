#include "InstanceGroup.h"



InstanceGroup::InstanceGroup(Mesh* mesh, Program* p)
{
	m_mesh = mesh;
	m_program = p;
}


InstanceGroup::~InstanceGroup()
{
}

void InstanceGroup::addEntities(std::vector<Entity*> entities)
{
	std::vector<Entity*> result;
	result.reserve(m_entities.size() + entities.size()); // preallocate memory
	result.insert(result.end(), m_entities.begin(), m_entities.end());
	result.insert(result.end(), entities.begin(), entities.end());
	m_entities = result;
}

void InstanceGroup::addEntity(Entity * entity)
{
	m_entities.push_back(entity);
}

std::vector<Entity*> InstanceGroup::getEntities()
{
	return m_entities;
}

Entity * InstanceGroup::getSample()
{
	return m_entities[0];
}

Mesh * InstanceGroup::getMesh()
{
	return m_mesh;
}

Program * InstanceGroup::getProgram()
{
	return m_program;
}
