#pragma once

#include <GL/glew.h>
#include <iostream>

static bool checkGLError(std::string part) {
	GLenum err = glGetError();
	if (err != GL_NO_ERROR) {
		std::cout << "GL Error no. " << err << " at: " << part << std::endl;
		return true;
	}
	return false;
}