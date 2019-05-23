#pragma once

#include "Model.h"
#include "Material.h"
#include <string>
#include <sstream>
#include "EngineConstants.h"
#include "TextureManager.h"

class ModelFromFile : public Model
{
public:
	ModelFromFile(std::string name);
	~ModelFromFile();
	void init(TextureManager* texManager);
	void draw(Program* p) override;
	std::string getPath();
	std::vector<Material*> parseMtl(std::string path, TextureManager* texManager);
private:
	Material* findMaterial(std::string name);
	std::string m_objPath;
	std::vector<Material*> m_materialMap;
};

