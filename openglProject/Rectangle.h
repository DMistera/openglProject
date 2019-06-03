#pragma once

#include "Polygon.h"

class Rectangle : public Polygon
{
public:
	Rectangle(float width, float heigth);
	Rectangle(glm::vec2 a, glm::vec2 b);
	~Rectangle();
	bool intersects(Rectangle other);
private:
	float m_width;
	float m_height;

	virtual std::vector<glm::vec2> getBaseVertices() override;
	virtual Type getType() override;
};

