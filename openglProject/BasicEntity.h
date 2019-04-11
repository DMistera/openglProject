#pragma once

#include "Entity.h"
#include "Material.h"
#include "ResourceManager.h"
#include "LightSource.h"
#include <vector>

class BasicEntity :
	public Entity
{
public:
	BasicEntity(Model* mesh);
	~BasicEntity();
	void init(ResourceManager* manager);
	void setMaterial(Material material);
	void addLightSource(LightSource* light);
protected:
	void setUniforms(Camera* camera);
	Material m_material;
	std::vector<LightSource*> m_lightSources;
};

