#include <iostream>

// library includes
#include "SDL2/SDL.h"
#include "SDL2pp/SDL2pp.hh"

// local includes
#include "Game.h"

using namespace std;

// TODO: Do better resource including
const std::string RESOURCE_PATH = "/home/patrick/ClionProjects/sdl-game/res/";
std::string FONT_NAME = "OpenSans-Regular.ttf";

SDL2pp::Texture renderText(SDL2pp::Renderer &renderer, SDL2pp::Font &font, const char *text)
{
    return SDL2pp::Texture(renderer, font.RenderText_Solid(text, SDL_Color{255, 255, 255, 255}));
}

/**
 * Test test test
 * @return exitCode
 */
int main()
{
    try
    {
        lg::Game game("HelloWorld");
        game.main();
        /*
        // init code
        SDL2pp::SDL sdl(SDL_INIT_VIDEO);
        SDL2pp::SDLTTF sdl_ttf;

        // load resources
        std::string fontPath = RESOURCE_PATH;
        fontPath += FONT_NAME;

        SDL2pp::Font font(fontPath.c_str(), 20);

        SDL2pp::Window window("test", 10, 10, 640, 480, SDL_WINDOW_RESIZABLE);

        std::shared_ptr<SDL2pp::Renderer> renderer =
                make_shared<SDL2pp::Renderer>(window, -1, SDL_RENDERER_ACCELERATED  | SDL_RENDERER_PRESENTVSYNC);

        SDL2pp::Texture helloWorld = renderText(*renderer, font, "Hello World!");

        sdlGame::BattleUnit battle(renderer);

        int i = 0;
        SDL2pp::Point point(10, 10);
        SDL2pp::Point speed(1, 2);

        while (i < 500)
        {
            point += speed;

            renderer->Clear();

            renderer->Copy(helloWorld, SDL2pp::NullOpt, point);

            renderer->Present();

            i += 1;
        }*/
    }
    catch (std::exception &e)
    {
        std::wcout << "Error: " << e.what() << std::endl;
    }

    return 0;
}