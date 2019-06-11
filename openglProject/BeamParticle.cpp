#include "BeamParticle.h"

#include "ChamberFloor.h"

BeamParticle::BeamParticle()
{
	m_radius = ChamberFloor::HOLE_SIZE/2.0f - 0.8f*RANDOM.nextFloat();
	m_angle = M_PI * 2.0f*RANDOM.nextFloat();
	float startY = 2.0f * RANDOM.nextFloat();
	float startX = cos(m_angle);
	float startZ = sin(m_angle);

	m_angularSpeed = 0.3f + 0.3f * RANDOM.nextFloat();;
	m_ascensionSpeed = 0.1f;

	m_rotOffsets = glm::vec3(M_PI*2.0f*RANDOM.nextFloat(), M_PI*2.0f*RANDOM.nextFloat(), M_PI*2.0f*RANDOM.nextFloat());
	m_rotRanges = glm::vec3(M_PI*(1.0f + RANDOM.nextFloat()), M_PI*(1.0f + RANDOM.nextFloat()), M_PI*(1.0f + RANDOM.nextFloat()));

	setPosition(glm::vec3(startX, startY, startZ));

	setScale(0.05f + 0.05f*RANDOM.nextFloat());
	m_elapsedTime = 0.0;

	update(0.0f);
}


BeamParticle::~BeamParticle()
{
}


void BeamParticle::update(double deltaTime)
{
	m_elapsedTime += deltaTime;
	
	glm::vec3 rot = m_rotation;
	glm::vec3 pos = m_position;

	rot = m_rotOffsets + (float)sin(m_elapsedTime)* m_rotRanges;

	m_angle += deltaTime * m_angularSpeed;

	pos.y += deltaTime * m_ascensionSpeed;
	if (pos.y >= 2.0f) {
		pos.y -= 2.0f;
	}
	pos.x = m_radius*cos(m_angle);
	pos.z = m_radius*sin(m_angle);

	setRotation(rot);
	setPosition(pos);
}

Model * BeamParticle::setModel(ResourceManager * res)
{
	Material* material = new Material();
	material->diffuseMap = res->getTextureManager()->getTexture("Feather.png", true);
	material->ambientMap = res->getTextureManager()->getTexture("Feather.png", true);
	RectangleModel* model = new RectangleModel(1.0f, 1.0f, material);
	model = dynamic_cast<RectangleModel*>(res->makeUniqueModel(model));
	return model;
}
