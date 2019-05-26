#pragma once

#include "Shape.h"
#include "Line2D.h"
#include <vector>
	
class Polygon : public Shape
{
public:
	Polygon();
	~Polygon();
	std::vector<glm::vec2> getVertices();
	std::vector<Line2D> getLines();
	virtual bool isPointInside(glm::vec2 point) override;
private:
	virtual std::vector<glm::vec2> getBaseVertices() = 0;

	// Inherited via Shape
	virtual Type getType() override;
};

