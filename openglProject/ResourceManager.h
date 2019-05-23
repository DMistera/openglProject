#pragma once

#include <vector>
#include "Program.h"
#include "ModelFromFile.h"

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	ModelFromFile* getModel(std::string path);
	Program* getProgram(std::string vertex, std::string fragment);
private:
	std::vector<ModelFromFile*> m_models;
	std::vector<Program*> m_programs;
	TextureManager m_textureManager;
};

