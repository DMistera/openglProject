#include "MtlParser.h"



std::vector<Material*> MtlParser::parse(std::string path)
{
	std::vector<Material*> result;
	std::ifstream in(ASSET_PATH + path);
	std::string line;
	Material* material = nullptr;
	while (std::getline(in, line)) {
		std::istringstream stream(line);
		std::string first;
		stream >> first;
		if (first == "newmtl") {
			if (material != nullptr) {
				result.push_back(material);
			}
			material = new Material();
			material->name = line.substr(7);
		}
		else if (first == "Ka") {
			glm::vec3 ambient;
			stream >> ambient.x; stream >> ambient.y; stream >> ambient.z; 
			material->ambient = ambient;
		}
		else if (first == "Kd") {
			glm::vec3 diffuse;
			stream >> diffuse.x; stream >> diffuse.y; stream >> diffuse.z;
			material->diffuse = diffuse;
		}
		else if (first == "Ks") {
			glm::vec3 specular;
			stream >> specular.x; stream >> specular.y; stream >> specular.z;
			material->specular = specular;
		}
		else if (first == "Ns") {
			stream >> material->shininess;
		}
		else if (first == "map_Ka") {
		}
		else if (first == "map_Kd") {
		}
		else if (first == "map_Ks") {
		}
		else if (first == "map_Ns") {
		}
	}
	if (material != nullptr) {
		result.push_back(material);
	}
	return result;
}

MtlParser::MtlParser()
{
}


MtlParser::~MtlParser()
{
}
