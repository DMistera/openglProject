#pragma once

#include <glm/vec2.hpp>

class MathUtils
{
public:
	MathUtils();
	~MathUtils();
	static float distance(glm::vec2 a, glm::vec2 b);
};

