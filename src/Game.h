//
// Created by patrick on 2/6/16.
//

#ifndef SDL_GAME_GAME_H
#define SDL_GAME_GAME_H

// library includes
#include <string>
#include "SDL2/SDL.h"
#include "SDL2pp/SDL2pp.hh"

// local includes
#include "Pointers.h"

namespace lg
{
    class Game
    {
    private:
        //SDL constructs
        SDL2pp::SDLPtr _sdl;
        SDL2pp::SDLTTFPtr _sdlttf;
        SDL2pp::WindowPtr _window;
        SDL2pp::RendererPtr _renderer;

        // Game constructs
        IScenePtr _scene;
        AssetManagerPtr _assets;
    public:
        Game(std::string title);

        // blocks until the game is finished running
        void main();
    };
}
#endif //SDL_GAME_GAME_H
