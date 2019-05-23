#include "PrismHitbox.h"



PrismHitbox::PrismHitbox(Shape* base, float minY, float maxY)
{
	m_base = base;
	m_minY = minY;
	m_maxY = maxY;
}


PrismHitbox::~PrismHitbox()
{
}

float PrismHitbox::getMinY()
{
	return m_minY;
}

float PrismHitbox::getMaxY()
{
	return m_maxY;
}

Shape * PrismHitbox::getBase()
{
	return m_base;
}

bool PrismHitbox::collidePrism(PrismHitbox * other)
{
	if (collideY(other)) {
		applyTransformToBase();
		other->applyTransformToBase();
		if (Intersecter2D::intersect(m_base, other->getBase())) {
			return true;
		}
	}
	return false;
}

void PrismHitbox::setPosition(glm::vec3 v)
{
	Transformable::setPosition(v);
	m_base->setPosition(glm::vec2(v.x, -v.z));
}

void PrismHitbox::setRotation(glm::vec3 v)
{
	Transformable::setRotation(v);
	m_base->setRotation(v.y);
}

void PrismHitbox::setScale(glm::vec3 v)
{
	Transformable::setScale(v);
	m_base->setScale(glm::vec2(v.x, v.y));
}

void PrismHitbox::inheritBasePosition()
{
	glm::vec2 basePos = m_base->getPosition();
	setPosition(glm::vec3(basePos.x, m_position.y, -basePos.y));
}

void PrismHitbox::applyTransformToBase()
{
	glm::vec3 g = getGlobalPosition();
	m_base->setPosition(glm::vec2(g.x, -g.z));
	glm::vec3 r = getGlobalRotation();
	m_base->setRotation(r.y);
}

std::vector<glm::vec3> PrismHitbox::getVertices()
{
	Polygon* base = dynamic_cast<Polygon*>(m_base);
	if (base == nullptr) {
		throw "Invalid base to get vertices";
	}
	else {
		std::vector<glm::vec3> result;
		std::vector<glm::vec2> baseVertices = base->getVertices();
		for (int i = 0; i < baseVertices.size(); i++) {
			glm::vec2 v = baseVertices[i];
			result.push_back(glm::vec3(v.x, m_minY, -v.y));
			result.push_back(glm::vec3(v.x, m_maxY, -v.y));
		}
		return result;
	}
}

#include "Entity.h"

void PrismHitbox::draw(ResourceManager * resourceManger, Camera * camera)
{
	std::vector<Vertex> vertices;
	std::vector<glm::vec3> positions = getVertices();
	for (int i = 0; i < positions.size(); i++) {
		Vertex v;
		v.position = glm::vec4(positions[i], 1.0f);
		vertices.push_back(v);
	}

	Program* solid = resourceManger->getProgram("v_constant.glsl", "f_constant.glsl");
	WireModel model(vertices);
	model;
	Entity e;
	e.setToDraw(&model, solid, camera);
	e.draw();
}

bool PrismHitbox::collideY(PrismHitbox * other)
{
	float o_minY = other->getMinY();
	float o_maxY = other->getMaxY();
	if (m_minY < o_minY) {
		return m_maxY > o_minY;
	}
	else {
		return o_maxY > m_minY;
	}
}

Hitbox::Type PrismHitbox::getType()
{
	return Hitbox::Type::PRISM;
}
