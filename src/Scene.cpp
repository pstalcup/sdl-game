//
// Created by patrick on 2/6/16.
//

#include "Scene.h"

#define FONT "OpenSans-Regular.ttf"

namespace lg
{
    Scene::Scene(GameData *data):
        _data(data),
        _card(nullptr),
        _cardText(nullptr),
        _selectedCard(nullptr),
        _fontName(FONT),
        _mouseX(0),
        _mouseY(0),
        _cardIndex(-1),
        _lastUpdate(0.0)
    {


        _card = data->getAssetManager().loadTexture(data->getRenderer(), "card.png");
        _cardText = data->getAssetManager().loadFontTexture(data->getRenderer(), _fontName, "Test", {0, 0, 0, 255});
    }

    void Scene::update(double dt)
    {

        if (_mouseY > 250)
        {
            if (_mouseX >= 10 && _mouseX <= 160)
            {
                _cardIndex = 0;
            }
            if (_mouseX >= 120 && _mouseX <= 220)
            {
                _cardIndex = 1;
            }
            if (_mouseX >= 230 && _mouseX <= 330)
            {
                _cardIndex = 2;
            }
        }


        _lastUpdate += dt;
        if (_lastUpdate > 0.05)
        {
            for (int i = 0; i < CARD_COUNT; ++i)
            {
                if (_cardIndex == i && _cardSteps[i] < 5)
                {
                    _cardSteps[i] += 1;
                }
                else if (_cardIndex != i && _cardSteps[i] > 0)
                {
                    _cardSteps[i] -= 1;
                }
            }

            _lastUpdate = 0.0;
        }
    }

    void Scene::render()
    {
        SDL2pp::Point offset(10, 5);
        SDL2pp::Point cardMotion(0, -5);

        // first card
        SDL2pp::Point card1 = SDL2pp::Point(10, 300) + cardMotion * _cardSteps[0];
        _data->getRenderer().Copy(*_card, SDL2pp::NullOpt, card1);
        _data->getRenderer().Copy(*_cardText, SDL2pp::NullOpt, card1 + offset);

        // second card
        SDL2pp::Point card2 = SDL2pp::Point(120, 300) + cardMotion * _cardSteps[1];
        _data->getRenderer().Copy(*_card, SDL2pp::NullOpt, card2);
        _data->getRenderer().Copy(*_cardText, SDL2pp::NullOpt, card2 + offset);

        // third card
        SDL2pp::Point card3 = SDL2pp::Point(230, 300) + cardMotion * _cardSteps[2];
        _data->getRenderer().Copy(*_card, SDL2pp::NullOpt, card3);
        _data->getRenderer().Copy(*_cardText, SDL2pp::NullOpt, card3 + offset);

        // Which card?
        if (_selectedCard != nullptr)
        {
            _data->getRenderer().Copy(*_selectedCard, SDL2pp::NullOpt, SDL2pp::Point(10, 10));
        }
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
            if (_cardIndex >= 0)
            {
                _selectedCard = _data->getAssetManager().
                        loadFontTexture(_data->getRenderer(), _fontName, std::to_string(_cardIndex),
                                        {255, 255, 255, 255});
            }
            else
            {
                _selectedCard = nullptr;
            }
        }

        return result;
    }
}