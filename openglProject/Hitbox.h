#pragma once

#include "Transformable.h"
#include "ResourceManager.h"
#include "Camera.h"

class Hitbox : public Transformable
{
public:
	enum Type {
		PRISM, GROUP
	};
	Hitbox();
	~Hitbox();
	bool collide(Hitbox* other);
	void resolve(Hitbox* solid, glm::vec3 shift);
	virtual Hitbox::Type getType() = 0;
	virtual void draw(ResourceManager* resourceManger, Camera* camera) = 0;
	virtual bool isPointInside(glm::vec3 p) = 0;
protected:
};
