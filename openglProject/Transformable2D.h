#pragma once

#include <glm/vec2.hpp>
#include <glm/mat2x2.hpp>
#include <iostream>

class Transformable2D
{
public:
	Transformable2D();
	~Transformable2D();
	void setPosition(glm::vec2 v);
	void setScale(glm::vec2 v);
	void setRotation(float rot);
	glm::vec2 getPosition();
	glm::vec2 getScale();
	float getRotation();
	glm::vec2 applyTransformation(glm::vec2 point);
	bool isinStartPosition();
private:
	glm::vec2 m_position;
	glm::vec2 m_scale;
	float m_rotation;
};

