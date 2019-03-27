#include "Face.h"



Face::Face(std::string line, std::vector <glm::vec4>* vertices, std::vector <glm::vec2>* textureCoords, std::vector <glm::vec3>* normals)
{
	std::string str = line.substr(2);
	std::vector<std::string> elements = split(str, ' ');
	for (int i = 0; i < elements.size(); i++) {
		Vertex f = readFaceElement(elements.at(i), vertices, textureCoords, normals);
		m_elements.push_back(f);
	}
}

std::vector<Vertex> Face::getTriangles()
{
	std::vector<Vertex> result;
	Vertex v1 = m_elements.at(0);
	Vertex v2;
	Vertex v3;
	for (int i = 1; i < m_elements.size() - 1; i++) {
		v2 = m_elements.at(i);
		v3 = m_elements.at(i + 1);
		result.push_back(v1);
		result.push_back(v2);
		result.push_back(v3);
	}
	return result;
}

Face::~Face()
{
}

Vertex Face::readFaceElement(std::string str, std::vector<glm::vec4>* vertices, std::vector<glm::vec2>* textureCoords, std::vector<glm::vec3>* normals)
{
	std::vector<std::string> splitStr = split(str, '/');
	Vertex result;
	int index1 = std::stoi(splitStr.at(0)) - 1;
	result.position = vertices->at(index1);
	try {
		int index2 = std::stoi(splitStr.at(1)) - 1;
		result.texCoord = textureCoords->at(index2);
	}
	catch (std::invalid_argument e) {
		result.texCoord = glm::vec3();
	}
	try {
		int index3 = std::stoi(splitStr.at(2)) - 1;
		result.normal = normals->at(index3);
	}
	catch (std::invalid_argument e) {
		std::cout << "Invalid argument for normals!" << std::endl;
		result.normal = glm::vec3();
	}
	return result;
}
