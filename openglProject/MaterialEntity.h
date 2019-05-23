#pragma once

#include "Entity.h"
#include "Material.h"
#include "ResourceManager.h"
#include "LightSource.h"
#include <vector>

class MaterialEntity :
	public Entity
{
public:
	MaterialEntity(ModelFromFile* mesh);
	~MaterialEntity();
	void init(ResourceManager* manager, Camera* camera);
	void setMaterial(Material material);
	void addLightSource(LightSource* light);
protected:
	void setUniforms();
	Material m_material;
	std::vector<LightSource*> m_lightSources;
};

