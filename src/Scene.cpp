//
// Created by patrick on 2/6/16.
//

#include "Scene.h"
#include "Hand.h"

namespace lg
{
    Scene::Scene(GameData *data):
        _data(data),
        _selectedCard(nullptr),
        _fontName("OpenSans-Regular.ttf"),
        _mouseX(0),
        _mouseY(0),
        _cardIndex(-1),
        _lastUpdate(0.0),
        _hand(new Hand(_data))
    {
    }

    void Scene::update(double dt)
    {
        _hand->update(dt);
    }

    void Scene::render()
    {
        _hand->render();
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

            _hand->mouseMoved(_mouseX, _mouseY);
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            int newIndex = _hand->getSelectedCard();

            if (_cardIndex != newIndex && newIndex >= 0)
            {
                _selectedCard = _data->getAssetManager().
                        loadFontTexture(_data->getRenderer(), _fontName, std::to_string(_cardIndex),
                                        {255, 255, 255, 255});
            }
            else if(newIndex == -1)
            {
                _selectedCard = nullptr;
            }

            _cardIndex = newIndex;
        }

        return result;
    }
}