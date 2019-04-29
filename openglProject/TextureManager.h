#pragma once

#include "Texture.h"
#include <vector>

class TextureManager
{
public:
	TextureManager();
	~TextureManager();
	Texture* getTexture(std::string path, bool gammaCorrelation);
private:
	std::vector<Texture*> m_textures;
};

