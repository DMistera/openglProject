#pragma once

#include "Transformable.h"

class Hitbox : public Transformable
{
public:
	enum Type {
		PRISM, GROUP
	};
	Hitbox();
	~Hitbox();
	bool collide(Hitbox* other);
	virtual Hitbox::Type getType() = 0;
protected:
};
