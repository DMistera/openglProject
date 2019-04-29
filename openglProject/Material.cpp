#include "Material.h"

Material::Material()
{
}

Material::~Material()
{
}

void Material::use(Program * p)
{
	glUniform3fv(p->getLocation("material.ambientColor"), 1, glm::value_ptr(ambientColor));
	glUniform3fv(p->getLocation("material.diffuseColor"), 1, glm::value_ptr(diffuseColor));
	glUniform3fv(p->getLocation("material.specularColor"), 1, glm::value_ptr(specularColor));
	glUniform1f(p->getLocation("material.shininess"), shininess);
	if (ambientMap != nullptr) {
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(p->getLocation("material.ambientMap"), 0);
		ambientMap->bind();
	}
	if (diffuseMap != nullptr) {
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(p->getLocation("material.diffuseMap"), 0);
		diffuseMap->bind();
	}
	if (specularMap != nullptr) {
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(p->getLocation("material.specularMap"), 0);
		specularMap->bind();
	}
	if (normalMap != nullptr) {
		glActiveTexture(GL_TEXTURE1);
		glUniform1i(p->getLocation("material.normalMap"), 1);
		normalMap->bind();
	}
}
