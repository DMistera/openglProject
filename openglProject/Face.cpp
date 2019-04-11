#include "Face.h"



Face::Face(std::string line)
{
	std::string str = line.substr(2);
	std::vector<std::string> elements = split(str, ' ');
	for (int i = 0; i < elements.size(); i++) {
		FaceTuple tuple = readFaceElement(elements.at(i));
		m_tuples.push_back(tuple);
	}
}

std::vector<FaceTuple> Face::getTuples()
{
	std::vector<FaceTuple> result;
	result.push_back(m_tuples[0]);
	result.push_back(m_tuples[1]);
	result.push_back(m_tuples[2]);
	for (int i = 3; i < m_tuples.size(); i++) {
		result.push_back(m_tuples[0]);
		result.push_back(m_tuples[i - 1]);
		result.push_back(m_tuples[i]);
	}
	return result;
}

Face::~Face()
{
}

FaceTuple Face::readFaceElement(std::string str)
{
	FaceTuple tuple;
	std::vector<std::string> splitStr = split(str, '/');
	tuple.positionIndex = std::stoi(splitStr.at(0)) - 1;
	if (splitStr.size() >= 2 && splitStr.at(1).length() > 0) {
		tuple.textureIndex = std::stoi(splitStr.at(1)) - 1;
	}
	else {
		tuple.textureIndex = -1;
	}
	if (splitStr.size() >= 3 && splitStr.at(2).length() > 0) {
		tuple.normalIndex = std::stoi(splitStr.at(2)) - 1;
	}
	else {
		tuple.normalIndex = -1;
	}
	return tuple;
}

bool FaceTuple::operator==(FaceTuple other)
{
	return positionIndex == other.positionIndex && normalIndex == other.normalIndex && textureIndex == other.textureIndex;
}
