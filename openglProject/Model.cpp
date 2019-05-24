#include "Model.h"



Model::Model()
{
}


Model::~Model()
{
	for (auto mesh : m_meshes) {
		delete mesh;
	}
	m_meshes.clear();
}

std::vector<Mesh*> Model::getMeshes()
{
	return m_meshes;
}
