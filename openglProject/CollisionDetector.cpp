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
			return prismToGroup(dynamic_cast<PrismHitbox*>(first), dynamic_cast<HitboxGroup*>(second));
		}
	}
	else {
		if (second->getType() == Hitbox::Type::PRISM) {
			return prismToGroup(dynamic_cast<PrismHitbox*>(second), dynamic_cast<HitboxGroup*>(first));
		}
		else {
			//TODO Group to group
		}
	}
	return false;
}

bool CollisionDetector::prismToGroup(PrismHitbox * prism, HitboxGroup * group)
{
	std::vector<Hitbox*> groupHitboxes = group->getChildren();
	for (int i = 0; i < groupHitboxes.size(); i++) {
		if (prism->collide(groupHitboxes[i])) {
			return true;
		}
	}
	return false;
}
