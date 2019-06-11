#pragma once
#include "Entity.h"
#include "PrismHitbox.h"
#include "BeamParticle.h"

class Beam :
	public Entity
{
public:
	Beam(ResourceManager* manager, Camera* camera);
	~Beam();
	void update(double deltaTime);
	PrismHitbox* getHitbox();
private:
	PrismHitbox* m_hitbox;
};

