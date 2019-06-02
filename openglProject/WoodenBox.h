#pragma once
#include "MaterialEntity.h"
#include "PrismHitbox.h"


class WoodenBox :
	public MaterialEntity
{
public:
	WoodenBox(ResourceManager* manager, Camera* camera);
	~WoodenBox();
	PrismHitbox* getHitbox();
private:
	PrismHitbox* m_hitbox;
};

