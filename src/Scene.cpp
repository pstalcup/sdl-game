//
// Created by patrick on 2/6/16.
//

#include "Scene.h"

namespace lg
{
    Scene::Scene(GameData *data):
        _data(data),
        _hellool(nullptr),
        _helloolText(nullptr),
        _font(nullptr),
        _mouseX(0),
        _mouseY(0),
        _cardIndex(0)
    {
        _hellool = data->getAssetManager().loadTexture(data->getRenderer(), "card.png");
        _font = data->getAssetManager().loadFont("OpenSans-Regular.ttf");
        _helloolText = new SDL2pp::Texture(data->getRenderer(),
                                           // blapck
                                           _font->RenderText_Solid("Helool?", {0, 0, 0, 255}));
    }

    void Scene::update()
    {
        for (int i = 0; i < CARD_COUNT; ++i)
        {
            if (_cardIndex == i && _cardSteps[i] < 5)
            {
                _cardSteps[i] += 1;
            }
        }
    }

    void Scene::render()
    {
        SDL2pp::Point offset(10, 5);
        SDL2pp::Point cardMotion(0, -5);

        // first card
        SDL2pp::Point card1 = SDL2pp::Point(10, 300); // - cardMotion * _cardSteps[0];
        _data->getRenderer().Copy(*_hellool, SDL2pp::NullOpt, card1);
        _data->getRenderer().Copy(*_helloolText, SDL2pp::NullOpt, card1 + offset);

        // second card
        SDL2pp::Point card2 = SDL2pp::Point(180, 300) - cardMotion * _cardSteps[1];
        _data->getRenderer().Copy(*_hellool, SDL2pp::NullOpt, card2);
        _data->getRenderer().Copy(*_helloolText, SDL2pp::NullOpt, card2 + offset);

        // third card
        SDL2pp::Point card3 = SDL2pp::Point(350, 300) - cardMotion * _cardSteps[2];
        _data->getRenderer().Copy(*_hellool, SDL2pp::NullOpt, card3 - cardMotion * _cardSteps[2]);
        _data->getRenderer().Copy(*_helloolText, SDL2pp::NullOpt, card3 + offset - cardMotion * _cardSteps[2]);
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
                default:
                    break;
            }
        }
        else if (event.type == SDL_MOUSEMOTION)
        {
            _mouseX = event.motion.x;
            _mouseY = event.motion.y;
            _cardIndex = -1;
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            std::cout << (event.button.x - 50) << ", " << (event.button.y - 75) << std::endl;
        }

        return result;
    }
}