#include "Program.h"



Program::Program()
{
}

bool Program::create(const char* vertexPath, const char* fragmentPath)
{
	//Obtain program id
	m_id = glCreateProgram();

	//Initialize shaders
	Shader vertex, fragment;
	if (!vertex.init(vertexPath)) {
		return false;
	}
	if (!fragment.init(fragmentPath)) {
		return false;
	}

	//Attach shaders to program
	glAttachShader(m_id, vertex.getID());
	glAttachShader(m_id, fragment.getID());

	//Link program
	glLinkProgram(m_id);

	GLint result;
	glGetProgramiv(m_id, GL_LINK_STATUS, &result);
	if (result == GL_FALSE) {
		perror("Failed to link program!");
		//TOOD Display a log here
		return false;
	}
	return true;
}


Program::~Program()
{
}
