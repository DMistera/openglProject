#include "CylinderHitbox.h"



CylinderHitbox::CylinderHitbox()
{
}


CylinderHitbox::~CylinderHitbox()
{
}

Hitbox::Type CylinderHitbox::getType()
{
	return CYLINDER;
}

bool CylinderHitbox::collide2D(Hitbox * other)
{
	if (other->getType() == CYLINDER) {
		CylinderHitbox* cylinder = dynamic_cast<CylinderHitbox*>(other);
		float distance = MathUtils::distance(cylinder-)
	}
	else if(other->getType() == CUBOID) {

	}
	return false;
}
