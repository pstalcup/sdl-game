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

            _scene->update();

            _data->getRenderer().Clear();
            _scene->render();
            _data->getRenderer().Present();

            // Frame limit
            SDL_Delay(1);
        }
    }
}