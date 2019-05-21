#pragma once

#include "Hitbox.h"
#include <vector>

class HitboxGroup : public Hitbox
{
public:
	HitboxGroup();
	~HitboxGroup();
	void addHitbox(Hitbox* hitbox);
	std::vector<Hitbox*> getChildren();
private:
	std::vector<Hitbox*> m_hitboxes;

	// Inherited via Hitbox
	virtual Hitbox::Type getType() override;
};

