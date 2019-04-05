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
	if (m_onUse != nullptr) {
		m_onUse();
	}
}

void Program::setUniformMat4(glm::mat4 value, const char * identifier)
{
	glUniformMatrix4fv(glGetUniformLocation(m_id, identifier), 1, GL_FALSE, glm::value_ptr(value));
}

void Program::setUniformVec4(glm::vec4 value, const char * identifier)
{
	glUniform4fv(glGetUniformLocation(m_id, identifier), 1, glm::value_ptr(value));
}

void Program::setUniformVec3(glm::vec3 value, const char * identifier)
{
	glUniform3fv(glGetUniformLocation(m_id, identifier), 1, glm::value_ptr(value));
}

void Program::setOnUse(std::function<void()> lambda)
{
	m_onUse = lambda;
}


Program::~Program()
{
}
