#pragma once

#include <vector>
#include "Material.h"
#include <string>
#include <fstream>
#include <sstream>
#include "EngineConstants.h"

class MtlParser
{
public:
	static std::vector<Material*> parse(std::string path);
	MtlParser();
	~MtlParser();
};

