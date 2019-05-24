#include "Hitbox.h"



Hitbox::Hitbox()
{
}


Hitbox::~Hitbox()
{
}

#include "CollisionDetector.h"

bool Hitbox::collide(Hitbox * other)
{
	return CollisionDetector::collide(this, other);
}

void Hitbox::resolve(Hitbox * solid)
{
	CollisionDetector::resolve(this, solid);
}




