//
// Created by patrick on 2/8/16.
//

#ifndef SDL_GAME_GAMEDATA_H
#define SDL_GAME_GAMEDATA_H

#include "SDL2pp/SDL2pp.hh"
#include "AssetManager.h"

namespace lg
{
    class GameData
    {
    private:
        // engine constructs
        SDL2pp::SDL _sdl;
        SDL2pp::SDLTTF _sdlttf;
        SDL2pp::Window _window;

        // publicly accessible members
        SDL2pp::Renderer _renderer;
        AssetManager _assets;
    public:
        GameData(std::string title);

        SDL2pp::Renderer& getRenderer();
        AssetManager& getAssetManager();

        std::string getFont();
    };

}


#endif //SDL_GAME_GAMEDATA_H
