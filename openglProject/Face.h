#pragma once

#include <glm/vec4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <string>
#include <vector>
#include "Utils.h"
#include <iostream>

struct FaceTuple {
	int positionIndex;
	int normalIndex;
	int textureIndex;
	bool operator ==(FaceTuple other);
};

class Face
{
public:
	Face(std::string line);
	std::vector<FaceTuple> getTuples();
	~Face();
private:
	FaceTuple readFaceElement(std::string str);
	std::vector<FaceTuple> m_tuples;
};

