#pragma once

#include "Hitbox.h"
#include "Circle.h"
#include "MathUtils.h"
#include <glm/vec2.hpp>

class CylinderHitbox : public Hitbox
{
public:
	CylinderHitbox();
	~CylinderHitbox();
	virtual Type getType() override;

	virtual bool collide2D(Hitbox * other) override;
private:
	Circle base;
};

