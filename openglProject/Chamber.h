#pragma once

#include "MaterialEntity.h"
#include "PrismHitbox.h"
#include "Circle.h"

class Chamber : public MaterialEntity
{
public:
	Chamber(ResourceManager* manager);
	~Chamber();
	PrismHitbox* getHitbox();
	virtual void updateMatrix() override;
private:
	PrismHitbox m_hitbox = PrismHitbox(new Circle(0.1f), 0.0f, 1.0f);;
};

