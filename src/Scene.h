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
#include "Pointers.h"

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
        virtual void update() = 0;
        virtual SceneEvent handleEvent(SDL_Event &event) = 0;
    };

    class Scene : public IScene
    {
    private:
        SDL2pp::RendererPtr _renderer;
        AssetManagerPtr _assets;

        SDL2pp::TexturePtr _helloWorld;
        SDL2pp::PointPtr _point;
    public:
        Scene(std::shared_ptr<SDL2pp::Renderer>, std::shared_ptr<AssetManager>);
        void render() override;
        void update() override;
        SceneEvent handleEvent(SDL_Event &event) override;
    };

}


#endif //SDL_GAME_SCENE_H
