#include "Texture.h"



Texture::Texture(std::string path)
{
	m_path = path;
}

void Texture::init(int textureUnit, bool gammaCorrelation)
{


	checkGLError("Before texture initialization.");
	glActiveTexture(GL_TEXTURE0 + textureUnit);;
	FIBITMAP* bitmap = FreeImage_Load(FreeImage_GetFileType((ASSET_PATH + m_path).c_str(), 0), (ASSET_PATH + m_path).c_str());
	//bitmap = FreeImage_ConvertTo32Bits(bitmap);
	unsigned int width = FreeImage_GetWidth(bitmap);
	unsigned int height = FreeImage_GetHeight(bitmap);
	if (bitmap) {
		glGenTextures(1, &m_id);
		glBindTexture(GL_TEXTURE_2D, m_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		GLenum type = gammaCorrelation ? GL_SRGB : GL_RGB8;
		glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(bitmap));
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
