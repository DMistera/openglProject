#pragma once

#include <vector>
#include "Program.h"
#include "Model.h"

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	Model* getModel(std::string path);
	Program* getProgram(std::string vertex, std::string fragment);
private:
	std::vector<Model*> m_models;
	std::vector<Program*> m_programs;
	TextureManager m_textureManager;
};

