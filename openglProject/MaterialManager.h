#pragma once

#include "Material.h"
#include "MtlParser.h"

class MaterialManager
{
public:
	MaterialManager();
	~MaterialManager();
	void addMaterials(std::string path);
	void addMaterial(Material* material);
	Material* getMaterial(std::string name);
private:
	std::vector<Material*> m_materials;
};

