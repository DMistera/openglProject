#include "ResourceManager.h"



ResourceManager::ResourceManager()
{
}


ResourceManager::~ResourceManager()
{
}

ModelFromFile * ResourceManager::getModel(std::string path)
{
	ModelFromFile* m = new ModelFromFile(path, &m_textureManager);
	m = dynamic_cast<ModelFromFile*>(makeUniqueModel(m));
	return m;
}

Model * ResourceManager::makeUniqueModel(Model * model)
{
	for (int i = 0; i < m_models.size(); i++) {
		Model* m = m_models.at(i);
		if (model == m) {
			delete model;
			return m;
		}
	}
	model->init();
	m_models.push_back(model);
	return model;
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

TextureManager * ResourceManager::getTextureManager()
{
	return &m_textureManager;
}
