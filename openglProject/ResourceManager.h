#pragma once

#include <vector>
#include "Program.h"
#include "Mesh.h"

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	Mesh* getMesh(const char* path);
	Program* getProgram(const char* vertex, const char* fragment);
private:
	std::vector<Mesh*> m_meshes;
	std::vector<Program*> m_programs;
};

