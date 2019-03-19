#pragma once

#include <vector>
#include <string>

static std::vector<std::string> split(std::string line, char separator) {
	std::vector<std::string> result;
	std::string temp = "";
	for (int i = 0; i < line.size(); i++) {
		char c = line.at(i);
		if (c != separator) {
			temp += c;
		}
		else {
			result.push_back(temp);
			temp = "";
		}
	}
	result.push_back(temp);
	return result;
}

static void pushVec3(std::vector<float>* vector, glm::vec3 vertex) {
	vector->push_back(vertex.x);
	vector->push_back(vertex.y);
	vector->push_back(vertex.z);
}