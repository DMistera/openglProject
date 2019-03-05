#include "Program.h"



Program::Program()
{
}

bool Program::create(const char* vertexPath, const char* fragmentPath)
{

	//Initialize shaders
	Shader vertex, fragment;
	if (!vertex.init(vertexPath, GL_VERTEX_SHADER)) {
		return false;
	}
	if (!fragment.init(fragmentPath, GL_FRAGMENT_SHADER)) {
		return false;
	}

	//Obtain program id
	m_id = glCreateProgram();

	//Attach shaders to program
	glAttachShader(m_id, vertex.getID());
	glAttachShader(m_id, fragment.getID());

	//Link program
	glLinkProgram(m_id);

	GLint result;
	glGetProgramiv(m_id, GL_LINK_STATUS, &result);
	if (result == GL_FALSE) {
		int infoLength;
		glGetProgramiv(m_id, GL_INFO_LOG_LENGTH, &infoLength);
		GLchar* errorMsg = new GLchar[infoLength];
		glGetProgramInfoLog(m_id, infoLength, NULL, errorMsg);
		std::cerr << "Failed to link program!\n" << errorMsg;
		return false;
	}

	return true;
}

void Program::use()
{
	glUseProgram(m_id);
}


Program::~Program()
{
}
