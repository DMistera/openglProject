#pragma once

#include <glm/vec4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <string>
#include <vector>
#include "Utils.h"
#include "Vertex.h"
#include <iostream>

class Face
{
public:
	Face(std::string line, std::vector <glm::vec4>* vertices, std::vector <glm::vec2>* textureCoords, std::vector <glm::vec3>* normals);
	std::vector<Vertex> getTriangles();
	std::vector<Vertex> m_elements;
	~Face();
private:
	Vertex readFaceElement(std::string str, std::vector <glm::vec4>* vertices, std::vector <glm::vec2>* textureCoords, std::vector <glm::vec3>* normals);

};

