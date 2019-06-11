#pragma once

#include <vector>
#include "Mesh.h"

class Model
{
public:
	Model();
	~Model();
	virtual void init() = 0;
	virtual void draw(Program* p) = 0;
	virtual bool operator ==(Model* another) = 0;
	std::vector<Mesh*> getMeshes();
protected:
	std::vector<Mesh*> m_meshes;
};

