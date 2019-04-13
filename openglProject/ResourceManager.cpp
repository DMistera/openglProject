#include "ResourceManager.h"



ResourceManager::ResourceManager()
{
}


ResourceManager::~ResourceManager()
{
}

Model * ResourceManager::getModel(std::string path)
{
	for (int i = 0; i < m_models.size(); i++) {
		Model* m = m_models.at(i);
		if (path == m->getPath()) {
			return m;
		}
	}
	Model* m = new Model(path);
	m->init(&m_textureManager);
	m_models.push_back(m);
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
