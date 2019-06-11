#pragma once

#include "MaterialEntity.h"
#include "ResourceManager.h"
#include "Hitbox.h"

#define _USE_MATH_DEFINES
#include <math.h>

class ChamberWall : public MaterialEntity
{
public:
	enum Position {
		FRONT, BACK, RIGHT, LEFT, UP, DOWN
	};
	ChamberWall(ResourceManager* manager, Position position);
	~ChamberWall();
	void open();
	Hitbox* getHitbox();
	void generateHitbox();
	static const float THICKNESS;
	static const float SIZE;
	bool isOpen();
protected:
	Hitbox* m_hitbox;
	bool m_open;
	ResourceManager* m_resourceManagerP;
	Position m_position;

	// Inherited via MaterialEntity
	virtual Model * setModel(ResourceManager * res) override;

	virtual ModelFromFile* getModelWhenClosed() = 0;
	virtual ModelFromFile* getModelWhenOpen() = 0;
	virtual Hitbox* getHitboxWhenOpen() = 0;
	virtual Hitbox* getHitboxWhenClosed() = 0;
};

