#pragma once

#include "Hitbox.h"
#include "Shape.h"
#include "Intersecter2D.h"

class PrismHitbox : public Hitbox
{
public:
	PrismHitbox(Shape* base, float minY, float maxY);
	~PrismHitbox();
	float getMinY();
	float getMaxY();
	Shape* getBase();
	bool collidePrism(PrismHitbox* other);
	void setPosition(glm::vec3 v) override;
	void setRotation(glm::vec3 v) override;
	void setScale(glm::vec3 v) override;
	void inheritBasePosition();
private:
	bool collideY(PrismHitbox* other);
	Shape* m_base;
	float m_minY;
	float m_maxY;

	// Inherited via Hitbox
	virtual Hitbox::Type getType() override;
};

