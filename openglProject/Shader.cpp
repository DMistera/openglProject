#include "Shader.h"



Shader::Shader()
{
}

bool Shader::init(std::string path, GLenum type)
{
	//Obtain shader id
	m_id = glCreateShader(type);
	
	//Read the file
	std::string code;
	std::ifstream inputStream(path, std::ios::in);
	if (inputStream.is_open()) {
		std::stringstream sstr;
		sstr << inputStream.rdbuf();
		code = sstr.str();
		inputStream.close();
	}
	else {
		std::cerr << "Count not open shader's source file";
		return false;
	}
	const char* codePointer = code.c_str();

	//Compile shader
	glShaderSource(m_id, 1, &codePointer, NULL);
	glCompileShader(m_id);

	//Check for errors
	GLint result;
	glGetShaderiv(m_id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		GLint logLength = 0;
		GLchar* infoLog = new GLchar[logLength];
		glGetShaderiv(m_id, GL_INFO_LOG_LENGTH, &logLength);
		glGetShaderInfoLog(m_id, logLength, &logLength, infoLog);
		std::cerr << "Shader compilation was not successful!" << std::endl << infoLog;
		return false;
	}
	return true;
}


GLuint Shader::getID()
{
	return m_id;
}

Shader::~Shader()
{
}
