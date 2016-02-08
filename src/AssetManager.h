//
// Created by patrick on 2/6/16.
//

#ifndef SDL_GAME_ASSETMANAGER_H
#define SDL_GAME_ASSETMANAGER_H

// library includes
#include <map>
#include "SDL2pp/SDL2pp.hh"

// local includes
#include "Pointers.h"

namespace lg
{
    class AssetManager
    {
    private:
        std::string _resourcePath;
        std::map<std::string, std::unique_ptr<SDL2pp::Texture>> _textures;
        std::map<std::string, std::unique_ptr<SDL2pp::Font>> _fonts;
    public:
        // delete this so people don't try to copy it in dumb ways
        AssetManager(const AssetManager&) = delete;

        AssetManager(std::string path);

        SDL2pp::Texture* loadTexture(SDL2pp::Renderer& renderer, std::string);
        SDL2pp::Font* loadFont(std::string);
    };
}

#endif //SDL_GAME_ASSETMANAGER_H
