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
	ModelFromFile(std::string name, TextureManager* texManager);
	~ModelFromFile();
	void init() override;
	void draw(Program* p) override;
	std::string getPath();
	std::vector<Material*> parseMtl(std::string path, TextureManager* texManager);
private:
	Material* findMaterial(std::string name);
	std::string m_objPath;
	std::vector<Material*> m_materialMap;
	TextureManager* m_texManager;
	// Inherited via Model
	virtual bool operator==(Model * another) override;
};

