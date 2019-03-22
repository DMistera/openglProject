#include "Face.h"



Face::Face(std::string line, std::vector <glm::vec4>* vertices, std::vector <glm::vec2>* textureCoords, std::vector <glm::vec3>* normals)
{
	std::string str = line.substr(2);
	std::vector<std::string> elements = split(str, ' ');
	for (int i = 0; i < elements.size(); i++) {
		FaceElement f = readFaceElement(elements.at(i), vertices, textureCoords, normals);
		m_elements.push_back(f);
	}
}

std::vector<glm::vec4> Face::getTriangles()
{
	std::vector<glm::vec4> result;
	glm::vec4 v1 = m_elements.at(0).vertexPosition;
	glm::vec4 v2;
	glm::vec4 v3;
	for (int i = 1; i < m_elements.size() - 1; i++) {
		v2 = m_elements.at(i).vertexPosition;
		v3 = m_elements.at(i + 1).vertexPosition;
		result.push_back(v1);
		result.push_back(v2);
		result.push_back(v3);
	}
	return result;
}

glm::vec3 Face::getNormal()
{
	return m_elements.at(0).vertexNormal;
}


Face::~Face()
{
}

Face::FaceElement Face::readFaceElement(std::string str, std::vector<glm::vec4>* vertices, std::vector<glm::vec2>* textureCoords, std::vector<glm::vec3>* normals)
{
	std::vector<std::string> splitStr = split(str, '/');
	Face::FaceElement result;
	int index1 = std::stoi(splitStr.at(0)) - 1;
	result.vertexPosition = vertices->at(index1);
	try {
		int index2 = std::stoi(splitStr.at(1)) - 1;
		result.texture = vertices->at(index2);
	}
	catch (std::invalid_argument e) {
		result.texture = glm::vec3();
	}
	try {
		int index3 = std::stoi(splitStr.at(2)) - 1;
		result.vertexNormal = vertices->at(index3);
	}
	catch (std::invalid_argument e) {
		result.vertexNormal = glm::vec3();
	}
	return result;
}
