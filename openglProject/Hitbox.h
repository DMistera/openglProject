#pragma once
class Hitbox
{
public:
	Hitbox();
	~Hitbox();
	enum Type {
		CYLINDER, CUBOID
	};
	virtual Type getType() = 0;
	bool collide(Hitbox* other);
	float getMinY();
	float getMaxY();
	virtual bool collide2D(Hitbox* other) = 0;
protected:
	float m_minY;
	float m_maxY;
private:
	bool collideY(Hitbox* other);
};

