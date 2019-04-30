#pragma once

#include "Entity.h"
#include <vector>
#include <functional>
#include "InstanceGroup.h"

class Instancer
{
public:
	Instancer(Entity* entity);
	~Instancer();
	void draw();
	virtual void init() = 0;
protected:
	Entity* m_entity;
	virtual void setUniforms(Entity* sample) = 0;
	virtual bool inSameInstanceGroup(Entity*, Entity*) = 0;
	virtual void setInstancedVertexAttributes(std::vector<Entity*> entities) = 0;
};

