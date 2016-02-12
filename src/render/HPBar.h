//
// Created by patrick on 2/11/16.
//

#ifndef SDL_GAME_HPBAR_H
#define SDL_GAME_HPBAR_H

#include "SDL2/SDL.h"
#include "IComponent.h"
#include "GameData.h"

namespace lg
{
    class HPBar : IComponent
    {
    private:
        GameData *_data;

        SDL2pp::Texture *_text;

        int _x;
        int _y;

        SDL_Color _color;

        int _val;
        int _targetVal;
        double _lastUpdate;

        SDL2pp::Texture* _getHPText(int val);
    public:
        HPBar(GameData *data, int x, int y, SDL_Color color);

        void render() override;
        void update(double dt) override;

        void setHP(int target);
        int getHP();

    };
}

#endif //SDL_GAME_HPBAR_H
