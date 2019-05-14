#pragma once

#include "Shape.h"
#include <glm/vec2.hpp>

class Line2D : public Shape
{
public:
	Line2D(glm::vec2 start, glm::vec2 end);
	glm::vec2 getStartPoint();
	glm::vec2 getEndPoint();
	~Line2D();
private:
	glm::vec2 m_startPoint;
	glm::vec2 m_endPoint;

	// Inherited via Shape
	virtual Type getType() override;
};
