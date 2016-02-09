//
// Created by patrick on 2/6/16.
//

#include "Game.h"

namespace lg
{
    Game::Game(std::string title) :
        _data(new GameData(title))
    {
        _scene = std::unique_ptr<IScene>(new Scene(_data.get()));
    }

    void Game::main()
    {
        Uint32 lastUpdate = SDL_GetTicks();
        Uint32 thisUpdate = 0;

        while (1)
        {
            SDL_Event event;
            while(SDL_PollEvent(&event))
            {
                SceneEvent handled = _scene->handleEvent(event);

                switch(handled)
                {
                    case SE_QUIT:
                        return;
                    case SE_CONTINUE:
                        break;
                }
            }

            // calculate time since last frame
            thisUpdate = SDL_GetTicks();
            double dt = (thisUpdate - lastUpdate) / 1000.0;
            lastUpdate = thisUpdate;

            _scene->update(dt);

            _data->getRenderer().Clear();
            _scene->render();
            _data->getRenderer().Present();

            // Frame limit
            SDL_Delay(1);
        }
    }
}