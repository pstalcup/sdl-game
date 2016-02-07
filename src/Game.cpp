//
// Created by patrick on 2/6/16.
//

#include "Game.h"
#include "AssetManager.h"
#include "Scene.h"

namespace lg
{
    Game::Game(std::string title) :
        _sdl(std::make_shared<SDL2pp::SDL>(SDL_INIT_VIDEO)),
        _sdlttf(std::make_shared<SDL2pp::SDLTTF>()),
        _window(std::make_shared<SDL2pp::Window>(title, 10, 10, 640, 480, SDL_WINDOW_RESIZABLE)),
        _renderer(std::make_shared<SDL2pp::Renderer>(*_window, -1, SDL_RENDERER_ACCELERATED)),
        _assets(std::make_shared<AssetManager>(_renderer, std::string("/home/patrick/ClionProjects/sdl-game/res/")))
    {
        // for now, bootstrap in the only scene
        _scene = std::make_shared<Scene>(_renderer, _assets);
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
                }
            }

            _scene->update();

            _renderer->Clear();
            _scene->render();
            _renderer->Present();

            // Frame limit
            SDL_Delay(1);
        }
    }
}