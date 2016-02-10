//
// Created by patrick on 2/9/16.
//

#ifndef SDL_GAME_ICOMPONENT_H
#define SDL_GAME_ICOMPONENT_H

class IComponent
{
public:
    virtual void update(double dt) = 0;
    virtual void render() = 0;
};

#endif //SDL_GAME_ICOMPONENT_H
