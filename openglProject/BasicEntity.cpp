#include "BasicEntity.h"



BasicEntity::BasicEntity(Mesh * mesh) : Entity()
{
	m_mesh = mesh;
}

BasicEntity::~BasicEntity()
{
}

void BasicEntity::init(ResourceManager* manager)
{
	m_program = manager->getProgram("v_basic.glsl", "f_basic.glsl");
	m_material.ambient = glm::vec3(1.0f, 1.0f, 1.0f);
	m_material.diffuse = glm::vec3(1.0f, 1.0f, 1.0f);
	m_material.specular = glm::vec3(1.0f, 1.0f, 1.0f);
	m_material.shininess = 128.0f;
}

void BasicEntity::setMaterial(Material material)
{
	m_material = material;
}

void BasicEntity::addLightSource(LightSource * light)
{
	m_lightSources.push_back(light);
}

void BasicEntity::setUniforms(Camera * camera)
{
	Entity::setUniforms(camera);
	glUniform3fv(m_program->getLocation("material.ambientColor"), 1, glm::value_ptr(m_material.ambient));
	glUniform3fv(m_program->getLocation("material.diffuseColor"), 1, glm::value_ptr(m_material.diffuse));
	glUniform3fv(m_program->getLocation("material.specularColor"), 1, glm::value_ptr(m_material.specular));
	glUniform1f(m_program->getLocation("material.shininess"), m_material.shininess);

	for (int i = 0; i < m_lightSources.size(); i++) {
		LightSource* l = m_lightSources.at(i);
		std::string s;
		s = std::string("lights[") + std::to_string(i) + std::string("].position");
		glUniform3fv(m_program->getLocation(s.c_str()), 1, glm::value_ptr(l->getPosition()));
		s = std::string("lights[")  + std::to_string(i) + std::string("].ambientColor");
		glUniform3fv(m_program->getLocation(s.c_str()), 1, glm::value_ptr(l->getAmbientColor()));
		s = std::string("lights[") + std::to_string(i) + std::string("].diffuseColor");
		glUniform3fv(m_program->getLocation(s.c_str()), 1, glm::value_ptr(l->getDiffuseColor()));
		s = std::string("lights[") + std::to_string(i) + std::string("].specularColor");
		glUniform3fv(m_program->getLocation(s.c_str()), 1, glm::value_ptr(l->getSpecularColor()));
		s = std::string("lights[") + std::to_string(i) + std::string("].constant");
		glUniform1f(m_program->getLocation(s.c_str()), l->getConstant());
		s = std::string("lights[") + std::to_string(i) + std::string("].linear");
		glUniform1f(m_program->getLocation(s.c_str()), l->getLinear());
		s = std::string("lights[") + std::to_string(i) + std::string("].quadratic");
		glUniform1f(m_program->getLocation(s.c_str()), l->getQuadratic());
	}
}
