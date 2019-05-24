#pragma once

#include "Hitbox.h"
#include <vector>

class HitboxGroup : public Hitbox
{
public:
	HitboxGroup();
	~HitboxGroup();
	void addHitbox(Hitbox* hitbox, bool setParent = true);
	std::vector<Hitbox*> getChildren();
	virtual void draw(ResourceManager * resourceManger, Camera * camera) override;
private:
	std::vector<Hitbox*> m_hitboxes;

	// Inherited via Hitbox
	virtual Hitbox::Type getType() override;
};

