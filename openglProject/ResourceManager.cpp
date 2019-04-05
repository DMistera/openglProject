#include "ResourceManager.h"



ResourceManager::ResourceManager()
{
}


ResourceManager::~ResourceManager()
{
}

Mesh * ResourceManager::getMesh(const char * path)
{
	for (int i = 0; i < m_meshes.size(); i++) {
		Mesh* m = m_meshes.at(i);
		if (strcmp(path, m->getPath()) == 0) {
			return m;
		}
	}
	Mesh* m = new Mesh(path);
	m->init();
	m_meshes.push_back(m);
	return m;
}

Program * ResourceManager::getProgram(const char * vertex, const char * fragment)
{
	for (int i = 0; i < m_programs.size(); i++) {
		Program* p = m_programs.at(i);
		if (strcmp(p->getVertexPath(), vertex) == 0 && strcmp(p->getFragmentPath(), fragment) == 0) {
			return p;
		}
	}
	Program* p = new Program(vertex, fragment);
	p->init();
	m_programs.push_back(p);
	return p;
}
