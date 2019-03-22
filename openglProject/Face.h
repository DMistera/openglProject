#pragma once

#include <glm/vec4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <string>
#include <vector>
#include "Utils.h"

class Face
{
public:
	struct FaceElement {
		glm::vec4 vertexPosition;
		glm::vec3 vertexNormal;
		glm::vec2 texture;
	};
	Face(std::string line, std::vector <glm::vec4>* vertices, std::vector <glm::vec2>* textureCoords, std::vector <glm::vec3>* normals);
	std::vector<glm::vec4> getTriangles();
	glm::vec3 getNormal();
	std::vector<FaceElement> m_elements;
	~Face();
private:
	FaceElement readFaceElement(std::string str, std::vector <glm::vec4>* vertices, std::vector <glm::vec2>* textureCoords, std::vector <glm::vec3>* normals);

};

