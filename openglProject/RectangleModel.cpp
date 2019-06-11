#include "RectangleModel.h"



RectangleModel::RectangleModel(float width, float height, Material* m)
{
	m_width = width;
	m_height = height;
	m_material = m;
}


RectangleModel::~RectangleModel()
{
}

void RectangleModel::draw(Program * p)
{
	//TODO
}

bool RectangleModel::operator==(Model * another)
{
	RectangleModel* m = dynamic_cast<RectangleModel*>(another);
	if (m == nullptr) {
		return false;
	}
	Mesh* m1 = m_meshes[0];
	Mesh* m2 = another->getMeshes()[0];

	return m1->getMaterial() == m2->getMaterial();
}

void RectangleModel::init()
{
	float dx = m_width / 2.0f;
	float dy = m_height / 2.0f;
	std::vector<Vertex> vertices(4);
	//TODO normals
	vertices[0] = Vertex(glm::vec4(-dx, -dy, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f));
	vertices[1] = Vertex(glm::vec4(dx, -dy, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f));
	vertices[2] = Vertex(glm::vec4(dx, dy, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f));
	vertices[3] = Vertex(glm::vec4(-dx, dy, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f));

	std::vector<unsigned int> indices = { 0, 1, 3,     1, 2, 3 };

	Mesh* mesh = new Mesh("unnamed", vertices, indices, m_material);
	mesh->init();
	m_meshes.push_back(mesh);
}
