#pragma once

#include "Transformable.h"
#include "Program.h"
#include <vector>
#include "Camera.h"
#include "Model.h"
#include "LightSource.h"

class Entity : public Transformable
{
public:
	Entity();
	~Entity();

	void setToDraw(Model* m, Program* program);
	void addEntity(Entity* e);
	void draw(Camera* camera);
	Program* getProgram();
	virtual void addLightSource(LightSource* lightSource);
protected:
	virtual void setUniforms(Camera* camera);
	Model* m_model;
	Program* m_program;
	std::vector<Entity*> m_entities;
	bool m_drawable;
};

