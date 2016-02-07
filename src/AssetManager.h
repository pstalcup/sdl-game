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
        std::shared_ptr<SDL2pp::Renderer> _renderer;
        std::map<std::string, std::shared_ptr<SDL2pp::Texture>> _textures;
        std::map<std::string, std::shared_ptr<SDL2pp::Font>> _fonts;
    public:
        AssetManager(SDL2pp::RendererPtr renderer, std::string path);

        std::shared_ptr<SDL2pp::Texture> loadTexture(std::string);

        std::shared_ptr<SDL2pp::Font> loadFont(std::string);
    };
}

#endif //SDL_GAME_ASSETMANAGER_H
