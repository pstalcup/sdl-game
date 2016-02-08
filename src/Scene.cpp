//
// Created by patrick on 2/6/16.
//

#include "Scene.h"

namespace lg
{
    Scene::Scene(GameData *data):
        _data(data)
    {
    }

    void Scene::update()
    {
    }

    void Scene::render()
    {
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

        return result;
    }
}