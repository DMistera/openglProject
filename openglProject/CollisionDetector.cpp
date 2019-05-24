#include "CollisionDetector.h"



CollisionDetector::CollisionDetector()
{
}


CollisionDetector::~CollisionDetector()
{
}

bool CollisionDetector::collide(Hitbox * first, Hitbox * second)
{
	if (first->getType() == Hitbox::Type::PRISM) {
		if (second->getType() == Hitbox::Type::PRISM) {
			return dynamic_cast<PrismHitbox*>(first)->collidePrism(dynamic_cast<PrismHitbox*>(second));
		}
		else if (second->getType() == Hitbox::Type::GROUP) {
			return prismToGroupCollision(dynamic_cast<PrismHitbox*>(first), dynamic_cast<HitboxGroup*>(second));
		}
	}
	else {
		if (second->getType() == Hitbox::Type::PRISM) {
			return prismToGroupCollision(dynamic_cast<PrismHitbox*>(second), dynamic_cast<HitboxGroup*>(first));
		}
		else {
			//TODO Group to group
		}
	}
	return false;
}

void CollisionDetector::resolve(Hitbox * nonSolid, Hitbox * solid)
{
	if (nonSolid->getType() == Hitbox::Type::PRISM) {
		if (solid->getType() == Hitbox::Type::PRISM) {
			 dynamic_cast<PrismHitbox*>(nonSolid)->resolvePrism(dynamic_cast<PrismHitbox*>(solid));
		}
		else if (solid->getType() == Hitbox::Type::GROUP) {
			 prismToGroupResolve(dynamic_cast<PrismHitbox*>(nonSolid), dynamic_cast<HitboxGroup*>(solid));
		}
	}
}



bool CollisionDetector::prismToGroupCollision(PrismHitbox * prism, HitboxGroup * group)
{
	std::vector<Hitbox*> groupHitboxes = group->getChildren();
	for (int i = 0; i < groupHitboxes.size(); i++) {
		if (prism->collide(groupHitboxes[i])) {
			return true;
		}
	}
	return false;
}

void CollisionDetector::prismToGroupResolve(PrismHitbox * prism, HitboxGroup * group)
{
	std::vector<Hitbox*> groupHitboxes = group->getChildren();
	for (int i = 0; i < groupHitboxes.size(); i++) {
		resolve(prism, groupHitboxes[i]);
	}
}
