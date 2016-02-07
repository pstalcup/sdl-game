//
// Created by patrick on 2/6/16.
//

#include "AssetManager.h"

namespace lg
{
    AssetManager::AssetManager(SDL2pp::RendererPtr renderer, std::string path)
        :_renderer(renderer),
         _resourcePath(path)
    {
    }

    std::shared_ptr<SDL2pp::Texture> AssetManager::loadTexture(std::string name)
    {
        auto found = _textures.find(name);
        if (found == _textures.end())
        {
            auto actualPath = _resourcePath + name;

            return (_textures[name] = std::make_shared<SDL2pp::Texture>(*_renderer, actualPath));
        }
        return found->second;
    }

    std::shared_ptr<SDL2pp::Font> AssetManager::loadFont(std::string name)
    {
        auto found = _fonts.find(name);
        if (found == _fonts.end())
        {
            auto actualPath = _resourcePath + name;

            return (_fonts[name] = std::make_shared<SDL2pp::Font>(actualPath, 20, 0));
        }
        return found->second;
    }
}