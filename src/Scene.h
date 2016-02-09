//
// Created by patrick on 2/6/16.
//

#ifndef SDL_GAME_SCENE_H
#define SDL_GAME_SCENE_H

// library includes
#include <memory>
#include "SDL2/SDL.h"
#include "SDL2pp/SDL2pp.hh"

// local includes
#include "GameData.h"

namespace lg
{

    enum SceneEvent
    {
        SE_CONTINUE,
        SE_QUIT
    };

    class IScene
    {
    public:
        virtual void render() = 0;
        virtual void update(double dt) = 0;
        virtual SceneEvent handleEvent(SDL_Event &event) = 0;
    };

    class Scene : public IScene
    {
    private:
        // constants
        static constexpr int CARD_COUNT = 3;

        // members
        GameData *_data;

        SDL2pp::Texture *_card;
        SDL2pp::Texture *_cardText;
        SDL2pp::Texture *_selectedCard;

        std::string _fontName;

        int _mouseX;
        int _mouseY;

        int _cardIndex;
        int _cardSteps[CARD_COUNT] = {0};

        double _lastUpdate;
    public:
        Scene(GameData *data);
        void render() override;
        void update(double dt) override;
        SceneEvent handleEvent(SDL_Event &event) override;
    };

}


#endif //SDL_GAME_SCENE_H
