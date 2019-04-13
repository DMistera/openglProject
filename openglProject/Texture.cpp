#include "Texture.h"



Texture::Texture(std::string path)
{
	m_path = path;
}

void Texture::init(int textureUnit)
{
	checkGLError("Before texture initialization.");
	glActiveTexture(GL_TEXTURE0 + textureUnit);;
	std::vector<unsigned char>  image;
	unsigned int width, height;
	unsigned int error = lodepng::decode(image, width, height, ASSET_PATH + m_path);
	//width = findPower(width);
	//height = findPower(height);
	if (error == 0) {
		glGenTextures(1, &m_id);
		glBindTexture(GL_TEXTURE_2D, m_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cerr << "Failed to decode texture: " << m_path << std::endl;
	}
	checkGLError("Texture initialization.");
}


Texture::~Texture()
{
}

bool Texture::operator==(Texture another)
{
	return another.getPath() == m_path;
}

std::string Texture::getPath()
{
	return m_path;
}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, m_id);
}
