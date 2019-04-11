#pragma once

#include "Mesh.h"
#include "Material.h"
#include <string>
#include "MtlParser.h"
#include "EngineConstants.h"

class Model
{
public:
	Model(std::string name);
	~Model();
	void init();
	void draw();
	std::string getPath();
private:
	std::string m_objPath;
	std::vector<Mesh> m_meshes;
	std::vector<Material*> m_materialMap;
};

