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
	MaterialEntity();
	~MaterialEntity();
	void init(ResourceManager* manager, Camera* camera);
	void setMaterial(Material material);
	void addLightSource(LightSource* light);
	virtual Model* setModel(ResourceManager* res) = 0;
protected:
	void setUniforms();
	Material m_material;
	std::vector<LightSource*> m_lightSources;
};

