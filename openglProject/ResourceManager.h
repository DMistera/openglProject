#pragma once

#include <vector>
#include "Program.h"
#include "Mesh.h"

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	Mesh* getMesh(std::string path);
	Program* getProgram(std::string vertex, std::string fragment);
private:
	std::vector<Mesh*> m_meshes;
	std::vector<Program*> m_programs;
};

