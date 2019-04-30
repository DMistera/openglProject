#pragma once

#include "Mesh.h"
#include "Material.h"
#include <string>
#include <sstream>
#include "EngineConstants.h"
#include "TextureManager.h"

class Model
{
public:
	Model(std::string name);
	~Model();
	void init(TextureManager* texManager);
	void draw(Program* p);
	std::string getPath();
	std::vector<Material*> parseMtl(std::string path, TextureManager* texManager);
	std::vector<Mesh*> getMeshes();
private:
	Material* findMaterial(std::string name);
	std::string m_objPath;
	std::vector<Mesh*> m_meshes;
	std::vector<Material*> m_materialMap;
};

