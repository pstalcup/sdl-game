//
// Created by patrick on 2/6/16.
//

#include "AssetManager.h"

namespace lg
{
    AssetManager::AssetManager(std::string path)
        : _resourcePath(path)
    {
    }

    SDL2pp::Texture* AssetManager::loadTexture(SDL2pp::Renderer& renderer, std::string name)
    {
        auto found = _textures.find(name);
        if (found == _textures.end())
        {
            auto actualPath = _resourcePath.append(name);

            _textures[name] = std::unique_ptr<SDL2pp::Texture>(new SDL2pp::Texture(renderer, actualPath));

            found = _textures.find(name);
        }
        return found->second.get();
    }

    SDL2pp::Font* AssetManager::loadFont(std::string name)
    {
        auto found = _fonts.find(name);
        if (found == _fonts.end())
        {
            auto actualPath = _resourcePath.append(name);

            _fonts[name] = std::unique_ptr<SDL2pp::Font>(new SDL2pp::Font(actualPath, 20, 0));
        }
        return found->second.get();
    }
}