#pragma once

#include "Transformable.h"
#include "Mesh.h"
#include "Program.h"
#include <vector>
#include "Camera.h"

class Entity : public Transformable
{
public:
	Entity();
	~Entity();
	void setToDraw(Mesh* m, Program* program);
	void addEntity(Entity* e);
	void draw(Camera* camera);
	Program* getProgram();
private:
	Mesh* m_mesh;
	Program* m_program;
	std::vector<Entity*> m_entities;
};

