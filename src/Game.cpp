//
// Created by patrick on 2/6/16.
//

#include "Game.h"

namespace lg
{
    Game::Game(std::string title) :
        _data(new GameData(title))
    {
    }

    void Game::main()
    {
        //while (1)
        {
            SDL_Event event;
            while(SDL_PollEvent(&event))
            {
                /*SceneEvent handled;// = SE_QUIT;// = _scene->handleEvent(event);

                switch(handled)
                {
                    case SE_QUIT:
                        return;
                    case SE_CONTINUE:
                        break;
                }*/
            }

            //_scene->update();

            //_renderer->Clear();
            //_scene->render();
            //_renderer->Present();

            // Frame limit
            SDL_Delay(1);
        }
    }
}