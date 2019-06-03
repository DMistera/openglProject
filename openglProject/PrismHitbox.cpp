#include "PrismHitbox.h"



PrismHitbox::PrismHitbox(Shape* base, float minY, float maxY)
{
	m_base = base;
	m_height = maxY - minY;
	setPosition(glm::vec3(0.0f, minY, 0.0f));
}

PrismHitbox::PrismHitbox(Shape * base, float height)
{
	m_base = base;
	m_height = height;
}


PrismHitbox::~PrismHitbox()
{
	delete m_base;
}

float PrismHitbox::getMinY()
{
	return getGlobalPosition().y;
}

float PrismHitbox::getMaxY()
{
	return getGlobalPosition().y + m_height * getGlobalScale().y;
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

void PrismHitbox::resolvePrism(PrismHitbox * solid)
{
	if (collideY(solid)) {
		applyTransformToBase();
		Shape* otherBase = solid->getBase();
		if (otherBase->isPointInside(m_base->getPosition())) {
			resolveY(solid);
			if (m_onResolveY) {
				m_onResolveY();
			}
		}
		else {
			Intersecter2D::resolve(m_base, otherBase);
			inheritBasePosition();
		}
	}
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
	m_base->setRotation(-r.y);
	glm::vec3 s = getGlobalScale();
	m_base->setScale(glm::vec2(s.x, s.z));
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
			result.push_back(glm::vec3(v.x, getMinY(), -v.y));
			result.push_back(glm::vec3(v.x, getMaxY(), -v.y));
		}
		return result;
	}
}

void PrismHitbox::setOnResolveY(std::function<void()> f)
{
	m_onResolveY = f;
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
	Entity e;
	e.setToDraw(&model, solid, camera);
	e.draw();
}

bool PrismHitbox::collideY(PrismHitbox * other)
{
	float o_minY = other->getMinY();
	float o_maxY = other->getMaxY();
	if (getMinY() < o_minY) {
		return getMaxY() > o_minY;
	}
	else {
		return o_maxY > getMinY();
	}
}

void PrismHitbox::resolveY(PrismHitbox * solid)
{
	float middleY = (getMinY() + getMaxY()) / 2.0f;
	float otherMiddleY = (solid->getMinY() + solid->getMaxY()) / 2.0f;
	if (middleY > otherMiddleY) {
		setY(solid->getMaxY());
	}
	else {
		setY(solid->getMinY() - m_height * m_scale.y);
	}
}

Hitbox::Type PrismHitbox::getType()
{
	return Hitbox::Type::PRISM;
}

bool PrismHitbox::isPointInside(glm::vec3 p)
{
	applyTransformToBase();
	if (p.y >= getMinY() && p.y <= getMaxY()) {
		if (getBase()->isPointInside(glm::vec2(p.x, -p.z))) {
			return true;
		}
	}
	return false;
}
