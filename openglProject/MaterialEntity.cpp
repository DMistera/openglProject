#include "MaterialEntity.h"



MaterialEntity::MaterialEntity() : Entity()
{
}

MaterialEntity::~MaterialEntity()
{

}

void MaterialEntity::init(ResourceManager* manager, Camera* camera)
{
	m_model = setModel(manager);
	m_program = manager->getProgram("v_material.glsl", "f_material.glsl");
	m_camera = camera;
	m_drawable = true;
}

void MaterialEntity::setMaterial(Material material)
{
	m_material = material;
}

void MaterialEntity::addLightSource(LightSource * light)
{
	m_lightSources.push_back(light);
	Entity::addLightSource(light);
}

void MaterialEntity::setUniforms()
{
	Entity::setUniforms();
	//TODO Optimise this
	for (int i = 0; i < m_lightSources.size(); i++) {
		LightSource* l = m_lightSources.at(i);
		std::string s;
		s = std::string("lightPositions[") + std::to_string(i) + std::string("]");
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
