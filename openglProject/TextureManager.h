#pragma once

#include "Texture.h"

class TextureManager
{
public:
	TextureManager();
	~TextureManager();
	Texture* getTexture(std::string path);
private:
	std::vector<Texture*> m_textures;
};

