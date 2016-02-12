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
            auto actualPath = _resourcePath + name;

            _textures[name] = std::unique_ptr<SDL2pp::Texture>(new SDL2pp::Texture(renderer, actualPath));

            found = _textures.find(name);
        }
        return found->second.get();
    }

    SDL2pp::Texture* AssetManager::loadFontTexture(SDL2pp::Renderer& renderer, std::string font, std::string message, SDL_Color color)
    {
        auto hash = std::hash<std::string>();

        std::string r = std::to_string(color.r);
        std::string g = std::to_string(color.g);
        std::string b = std::to_string(color.b);
        std::string a = std::to_string(color.a);

        size_t result = hash(std::to_string(hash(message)) + r + g + b + a);

        auto found = _fontTextures.find(result);
        if (found == _fontTextures.end())
        {
            _fontTextures[result] = std::unique_ptr<SDL2pp::Texture>(
                new SDL2pp::Texture(renderer, loadFont(font)->RenderText_Solid(message.c_str(), color)));

            found = _fontTextures.find(result);
        }
        return found->second.get();
    }

    SDL2pp::Font* AssetManager::loadFont(std::string name)
    {
        auto found = _fonts.find(name);
        if (found == _fonts.end())
        {
            auto actualPath = _resourcePath + name;

            _fonts[name] = std::unique_ptr<SDL2pp::Font>(new SDL2pp::Font(actualPath, 16, 0));

            found = _fonts.find(name);
        }
        return found->second.get();
    }
}