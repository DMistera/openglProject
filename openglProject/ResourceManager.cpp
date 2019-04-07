#include "ResourceManager.h"



ResourceManager::ResourceManager()
{
}


ResourceManager::~ResourceManager()
{
}

Mesh * ResourceManager::getMesh(std::string path)
{
	for (int i = 0; i < m_meshes.size(); i++) {
		Mesh* m = m_meshes.at(i);
		if (path == m->getPath()) {
			return m;
		}
	}
	Mesh* m = new Mesh(path);
	m->init();
	m_meshes.push_back(m);
	return m;
}

Program * ResourceManager::getProgram(std::string vertex, std::string fragment)
{
	for (int i = 0; i < m_programs.size(); i++) {
		Program* p = m_programs.at(i);
		if (p->getVertexPath() == vertex && p->getFragmentPath() == fragment) {
			return p;
		}
	}
	Program* p = new Program(vertex, fragment);
	p->init();
	m_programs.push_back(p);
	return p;
}
