#pragma once

#include "Shape.h"
#include <glm/vec2.hpp>
#include <algorithm>

class Line2D : public Shape
{
public:
	enum Orientation {
		COLLINEAR, CLOCKWISE, COUNTER_CLOCKWISE
	};
	Line2D(glm::vec2 start, glm::vec2 end);
	glm::vec2 getStartPoint();
	glm::vec2 getEndPoint();
	glm::vec2 getInterpolatedPoint(float t);
	void getEquation(float* a, float* b);
	float distanceToPoint(glm::vec2 point);
	Orientation getOrientation(glm::vec2 p, glm::vec2 q, glm::vec2 r);
	bool instersects(Line2D other);
	bool isPoint();
	~Line2D();
private:
	glm::vec2 m_startPoint;
	glm::vec2 m_endPoint;

	// Inherited via Shape
	virtual Type getType() override;

	// Inherited via Shape
	virtual bool isPointInside(glm::vec2 point) override;
};

