//
// Created by patrick on 2/7/16.
//

#include "Card.h"
#include "AssetManager.h"

namespace lg
{
    Card::Card(SDL2pp::RendererPtr renderer, AssetManagerPtr assets):
        _renderer(renderer),
        _assets(assets),
        _card(nullptr),
        _x(100),
        _y(100),
        _angle(0.0)
    {
        _card = _assets->loadTexture("card.png");
    }

    void Card::render()
    {
        _renderer->Copy(*_card, SDL2pp::NullOpt, SDL2pp::Point(_x, _y), _angle, SDL2pp::Point(0, 150));
    }

    void Card::update()
    {
        _angle += 0.1;
    }

    void Card::select()
    {

    }
}