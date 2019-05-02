#pragma once

#include "Shape.h"
#include <vector>
	
class Polygon : public Shape
{
public:
	Polygon();
	~Polygon();
	std::vector<glm::vec2> getVertices();
private:
	virtual std::vector<glm::vec2> getBaseVertices() = 0;
};

