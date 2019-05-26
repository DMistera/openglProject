#pragma once

#include "Hitbox.h"
#include "Shape.h"
#include "Intersecter2D.h"
#include <functional>
#include "WireModel.h"

class PrismHitbox : public Hitbox
{
public:
	PrismHitbox(Shape* base, float minY, float maxY);
	PrismHitbox(Shape* base, float height);
	~PrismHitbox();
	float getMinY();
	float getMaxY();
	Shape* getBase();
	bool collidePrism(PrismHitbox* other);
	void resolvePrism(PrismHitbox* solid);
	void setPosition(glm::vec3 v) override;
	void setRotation(glm::vec3 v) override;
	void setScale(glm::vec3 v) override;
	void inheritBasePosition();
	void applyTransformToBase();
	std::vector<glm::vec3> getVertices();
	void setOnResolveY(std::function<void()> f);
	virtual void draw(ResourceManager* resourceManger, Camera* camera) override;
	virtual bool isPointInside(glm::vec3 p) override;
private:
	bool collideY(PrismHitbox* other);
	void resolveY(PrismHitbox* solid);
	Shape* m_base;
	float m_height;
	std::function<void()> m_onResolveY;

	// Inherited via Hitbox
	virtual Hitbox::Type getType() override;
};

