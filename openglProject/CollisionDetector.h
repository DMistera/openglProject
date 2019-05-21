#pragma once

#include "Hitbox.h"
#include "PrismHitbox.h"
#include "HitboxGroup.h"

class CollisionDetector
{
public:
	CollisionDetector();
	~CollisionDetector();
	static bool collide(Hitbox* first, Hitbox* second);
private:
	static bool prismToGroup(PrismHitbox* prism, HitboxGroup* group);
};

 