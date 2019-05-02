#include "MathUtils.h"



MathUtils::MathUtils()
{
}


MathUtils::~MathUtils()
{
}

float MathUtils::distance(glm::vec2 a, glm::vec2 b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}
