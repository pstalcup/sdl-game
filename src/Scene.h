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
#include "IComponent.h"

namespace lg
{

    // forward declare
    class Hand;

    enum SceneEvent
    {
        SE_CONTINUE,
        SE_QUIT
    };

    class IScene : public IComponent
    {
    public:
        virtual SceneEvent handleEvent(SDL_Event &event) = 0;
    };

    class Scene : public IScene
    {
    private:

        // members
        GameData *_data;

        SDL2pp::Texture *_selectedCard;

        std::string _fontName;

        int _mouseX;
        int _mouseY;

        int _cardIndex;

        double _lastUpdate;

        std::unique_ptr<Hand> _hand;
    public:
        Scene(GameData *data);
        void render() override;
        void update(double dt) override;
        SceneEvent handleEvent(SDL_Event &event) override;
    };

}


#endif //SDL_GAME_SCENE_H
