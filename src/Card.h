//
// Created by patrick on 2/7/16.
//

#ifndef SDL_GAME_CARD_H
#define SDL_GAME_CARD_H

#include "Pointers.h"

namespace lg
{
    class Card
    {
    private:
        SDL2pp::RendererPtr _renderer;
        AssetManagerPtr _assets;

        SDL2pp::TexturePtr _card;

        int _x;
        int _y;
        double _angle;
    public:
        Card(SDL2pp::RendererPtr, AssetManagerPtr assets);
        void render();
        void update();
        void select();
    };
}

#endif //SDL_GAME_CARD_H
