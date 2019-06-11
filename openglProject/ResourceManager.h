#pragma once

#include <vector>
#include "Program.h"
#include "ModelFromFile.h"
#include "RectangleModel.h"

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	ModelFromFile* getModel(std::string path);
	Model* makeUniqueModel(Model* model);
	Program* getProgram(std::string vertex, std::string fragment);
	TextureManager* getTextureManager();
private:
	std::vector<Model*> m_models;
	std::vector<Program*> m_programs;
	TextureManager m_textureManager;
};

