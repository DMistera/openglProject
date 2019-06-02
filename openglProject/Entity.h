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

	void setToDraw(Model* m, Program* program, Camera* camera);
	void addEntity(Entity* e);
	void draw();
	Program* getProgram();
	Model* getModel();
	Camera* getCamera();
	std::vector<Entity*> getEntities();
	bool isDrawable();
	virtual void addLightSource(LightSource* lightSource);
	virtual void setUniforms();
	void setChildrenUpdateCallback(std::function<void()> f);
protected:
	virtual void setInstanceUniforms();
	Model* m_model;
	Program* m_program;
	Camera* m_camera;
	bool m_drawable;
	std::function<void()> m_onChildrenUpdate;
	std::vector<Entity*> m_entities;
};

