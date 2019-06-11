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
	static void resolve(Hitbox* nonSolid, Hitbox* solid, glm::vec3 shift);
private:
	static bool prismToGroupCollision(PrismHitbox* prism, HitboxGroup* group);
	static void prismToGroupResolve(PrismHitbox* prism, HitboxGroup* group, glm::vec3 shift);
};

 