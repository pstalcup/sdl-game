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
        _point(nullptr),
        _angle(0.0)
    {
        auto openSans = _assets->loadFont("OpenSans-Regular.ttf");
        _card = _assets->loadTexture("card.png");

        _helloWorld = std::make_shared<SDL2pp::Texture>(*_renderer, openSans->RenderText_Solid("Hello World!", SDL_Color{0, 0, 0, 255}));
        _point = std::make_shared<SDL2pp::Point>(10, 10);
    }

    void Scene::update()
    {
        _angle += 0.1;
    }

    void Scene::render()
    {
        _card->SetBlendMode(SDL_BLENDMODE_BLEND);
        _renderer->Copy(*_card, SDL2pp::NullOpt, SDL2pp::Point(100, 100), -10.0, SDL2pp::Point(0, 150));
        _renderer->Copy(*_card, SDL2pp::NullOpt, SDL2pp::Point(100, 100), 0.0, SDL2pp::Point(0, 150));
        _renderer->Copy(*_card, SDL2pp::NullOpt, SDL2pp::Point(100, 100), 10.0, SDL2pp::Point(0, 150));
        //_renderer->Copy(*_helloWorld, SDL2pp::NullOpt, *_point);
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
        else if (event.type == SDL_MOUSEMOTION)
        {
            _mouseX = event.motion.x;
            _mouseY = event.motion.y;
        }
        return result;
    }
}