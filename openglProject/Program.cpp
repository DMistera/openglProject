#include "Program.h"



Program::Program(const char* vertexPath, const char* fragmentPath)
{
	m_vertexPath = vertexPath;
	m_fragmentPath = fragmentPath;
}

bool Program::init()
{

	//Initialize shaders
	Shader vertex, fragment;
	if (!vertex.init(m_vertexPath, GL_VERTEX_SHADER)) {
		return false;
	}
	if (!fragment.init(m_fragmentPath, GL_FRAGMENT_SHADER)) {
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
	if (m_onUse != nullptr) {
		m_onUse();
	}
}

void Program::setOnUse(std::function<void()> lambda)
{
	m_onUse = lambda;
}

GLuint Program::getLocation(const char * attributeName)
{
	return glGetUniformLocation(m_id, attributeName);
}

const char * Program::getVertexPath()
{
	return m_vertexPath;
}

const char * Program::getFragmentPath()
{
	return m_fragmentPath;
}


Program::~Program()
{
}
