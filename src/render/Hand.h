//
// Created by patrick on 2/9/16.
//

#ifndef SDL_GAME_HAND_H
#define SDL_GAME_HAND_H

#include "IComponent.h"
#include "GameData.h"

namespace lg
{
    class Hand : public IComponent
    {
    private:
        // constants
        static constexpr int CARD_COUNT = 3;

        GameData *_data;

        SDL2pp::Texture *_card;
        SDL2pp::Texture *_cardText;

        std::string _fontName;

        int _cardIndex;
        int _cardSteps[CARD_COUNT] = {0};

        double _lastUpdate;
    public:
        Hand(GameData *);
        void update(double dt) override;
        void render() override;

        void mouseMoved(int x, int y);
        int getSelectedCard();
    };
}

#endif //SDL_GAME_HAND_H
