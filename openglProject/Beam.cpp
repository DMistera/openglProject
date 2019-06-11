#include "Beam.h"


#include "ChamberFloor.h"

Beam::Beam(ResourceManager* manager, Camera* camera)
{
	TextureManager* texManager = manager->getTextureManager();

	for (int i = 0; i < 100; i++) {
		BeamParticle* b = new BeamParticle();
		b->init(manager, camera);
		addEntity(b);
	}

	m_hitbox = new PrismHitbox(new Circle(ChamberFloor::HOLE_SIZE/2.0f), 2.0f);
	m_hitbox->setParent(this);
}


Beam::~Beam()
{
}

void Beam::update(double deltaTime)
{
	for (Entity* e : m_entities) {
		BeamParticle* par = dynamic_cast<BeamParticle*>(e);
		par->update(deltaTime);
	}
}

PrismHitbox * Beam::getHitbox()
{
	return m_hitbox;
}
