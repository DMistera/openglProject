#pragma once

#include "Polygon.h"

class Rectangle : public Polygon
{
public:
	Rectangle();
	~Rectangle();

private:
	float m_width;
	float m_height;

	virtual std::vector<glm::vec2> getBaseVertices() override;
};

