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
#include "GameData.h"
#include "Scene.h"

namespace lg
{
    class Game
    {
    private:
        std::unique_ptr<GameData> _data;
        std::unique_ptr<IScene> _scene;
    public:
        Game(std::string title);

        // blocks until the game is finished running
        void main();
    };
}
#endif //SDL_GAME_GAME_H
