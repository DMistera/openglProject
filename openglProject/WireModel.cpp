#include "WireModel.h"



WireModel::WireModel(std::vector<Vertex> vertices)
{
	std::vector<unsigned int> indices;
	for (int i = 0; i < vertices.size(); i++) {
		indices.push_back(i);
	}


	Mesh* mesh = new Mesh("", vertices, indices);
	mesh->init();
	m_meshes.push_back(mesh);
}

WireModel::~WireModel()
{
}

void WireModel::draw(Program * p)
{
	m_meshes[0]->draw(p, GL_TRIANGLE_STRIP, true);
}
