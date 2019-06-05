#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <functional>

class Transformable
{
public:
	Transformable();
	~Transformable();
	glm::mat4 * getMatrix();
	virtual void updateMatrix();
	void setParent(Transformable* parent);
	virtual void setRotation(glm::vec3 v);
	virtual void setPosition(glm::vec3 v);
	void setPosition(glm::vec2 v);
	void setY(float y);
	void setRotationY(float r);
	void setPositionY(float y);
	virtual void setScale(glm::vec3 v);
	void setScale(glm::vec2 v);
	void setScale(float scale);
	void move(glm::vec2 v);
	void move(glm::vec3 v);
	glm::vec3 getGlobalPosition();
	glm::vec3 getGlobalRotation();
	glm::vec3 getGlobalScale();
protected:
	glm::vec3 m_position = glm::vec3(0.0f);
	glm::vec3 m_rotation = glm::vec3(0.0f);
	glm::vec3 m_scale = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::mat4 m_matrix;
	Transformable* m_parent;
	bool m_matrixOutdated;
};

