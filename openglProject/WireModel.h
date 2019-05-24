#pragma once

#include "Model.h"
#include <vector>
#include "Vertex.h"

class WireModel : public Model
{
public:
	WireModel(std::vector<Vertex> vertices);
	~WireModel();

	// Inherited via Model
	virtual void draw(Program * p) override;
private:
	Mesh* m_mesh;
};

