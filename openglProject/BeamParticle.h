#pragma once
#include "MaterialEntity.h"
#include "RectangleModel.h"

#define _USE_MATH_DEFINES
#include <math.h>

class BeamParticle :
	public MaterialEntity
{
public:
	BeamParticle();
	~BeamParticle();
	void update(double deltaTime);
	// Inherited via MaterialEntity
	virtual Model * setModel(ResourceManager * res) override;

private:
	float m_speedY;
	float m_radius;
	float m_angle;
	float m_angularSpeed;
	float m_ascensionSpeed;
	glm::vec3 m_rotRanges;
	glm::vec3 m_rotOffsets;

	
	double m_elapsedTime;
};

