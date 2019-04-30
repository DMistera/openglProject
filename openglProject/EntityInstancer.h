#pragma once

#include "Instancer.h"

class EntityInstancer : public Instancer
{
public:
	EntityInstancer(Entity* entity);
	~EntityInstancer();
	virtual void init() override;
protected:
	GLuint m_modelMatrixBuffer;

	virtual void setUniforms(Entity * sample) override;
	virtual bool inSameInstanceGroup(Entity *, Entity *) override;
	virtual void setInstancedVertexAttributes(std::vector<Entity*> entities) override;
};

