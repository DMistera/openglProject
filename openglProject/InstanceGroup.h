#pragma once

#include "Entity.h"
#include <vector>

class InstanceGroup
{
public:
	InstanceGroup(Mesh* mesh, Program* p);
	~InstanceGroup();
	void addEntities(std::vector<Entity*> entities);
	void addEntity(Entity* entity);
	std::vector<Entity*> getEntities();
	Entity* getSample();
	Mesh* getMesh();
	Program* getProgram();
private:
	Mesh* m_mesh;
	Program* m_program;
	std::vector<Entity*> m_entities;
};

