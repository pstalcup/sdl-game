//
// Created by patrick on 2/8/16.
//

#include "GameData.h"


#define RESOURCE_PATH "/home/patrick/ClionProjects/sdl-game"

namespace lg
{

    GameData::GameData(std::string title) :
        _sdl(SDL_INIT_VIDEO),
        _sdlttf(),
        _window(title, 0, 0, 640, 480, SDL_WINDOW_RESIZABLE),
        _renderer(_window, 1, 0),
        _assets(RESOURCE_PATH)
    {

    }

    SDL2pp::Renderer& GameData::getRenderer()
    {
        return _renderer;
    }

    AssetManager& GameData::getAssetManager()
    {
        return _assets;
    }
}