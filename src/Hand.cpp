//
// Created by patrick on 2/9/16.
//

#include "Hand.h"

namespace lg
{
    Hand::Hand(GameData *data):
            _data(data),
            _card(nullptr),
            _cardText(nullptr),
            _fontName("OpenSans-Regular.ttf"),
            _cardIndex(0),
            _lastUpdate(0.0)
    {
        _card = _data->getAssetManager().loadTexture(data->getRenderer(), "card.png");
        _cardText = _data->getAssetManager().loadFontTexture(data->getRenderer(), _fontName, "Test", {0, 0, 0, 255});
    }
    void Hand::render()
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
    }

    void Hand::update(double dt)
    {
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

    int Hand::getSelectedCard()
    {
        return _cardIndex;
    }

    void Hand::mouseMoved(int x, int y)
    {
        _cardIndex = -1;
        if (y > 250)
        {
            if (x >= 10 && x <= 160)
            {
                _cardIndex = 0;
            }
            if (x >= 120 && x <= 220)
            {
                _cardIndex = 1;
            }
            if (x >= 230 && x <= 330)
            {
                _cardIndex = 2;
            }
        }
    }
}