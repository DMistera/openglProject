#include "TextureManager.h"



TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

Texture * TextureManager::getTexture(std::string path, bool gammaCorrelation)
{
	for (int i = 0; i < m_textures.size(); i++) {
		if (path == m_textures.at(i)->getPath()) {
			return m_textures.at(i);
		}
	}
	Texture* tex = new Texture(path);
	tex->init(0, gammaCorrelation);
	m_textures.push_back(tex);
	return tex;
}
