//
// Created by patrick on 2/6/16.
//

#include "Scene.h"
#include "AssetManager.h"

namespace lg
{
    Scene::Scene(std::shared_ptr<SDL2pp::Renderer> renderer, std::shared_ptr<AssetManager> assets):
        _renderer(renderer),
        _assets(assets),
        _helloWorld(nullptr),
        _point(nullptr)
    {
        auto openSans = _assets->loadFont("OpenSans-Regular.ttf");

        _helloWorld = std::make_shared<SDL2pp::Texture>(*_renderer, openSans->RenderText_Solid("Hello World!", SDL_Color{255, 255, 255, 255}));
        _point = std::make_shared<SDL2pp::Point>(10, 10);
    }

    void Scene::update()
    {

    }

    void Scene::render()
    {
        _renderer->Copy(*_helloWorld, SDL2pp::NullOpt, *_point);
    }

    SceneEvent Scene::handleEvent(SDL_Event& event)
    {
        SceneEvent result = SE_CONTINUE;

        if (event.type == SDL_QUIT)
        {
            result = SE_QUIT;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    result = SE_QUIT;
                    break;
                case SDLK_RIGHT:
                    (*_point) += SDL2pp::Point(1, 0);
                    break;
                case SDLK_LEFT:
                    (*_point) += SDL2pp::Point(-1, 0);
                    break;
                case SDLK_UP:
                    (*_point) += SDL2pp::Point(0, -1);
                    break;
                case SDLK_DOWN:
                    (*_point) += SDL2pp::Point(0, 1);
                    break;
            }
        }
        return result;
    }
}