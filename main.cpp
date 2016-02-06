#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2pp/SDL2pp.hh"

using namespace std;

// TODO: Do better resource including
const std::string RESOURCE_PATH = "/home/patrick/ClionProjects/sdl-game/res/";
std::string FONT_NAME = "OpenSans-Regular.ttf";

int main()
{
    try
    {
        // init code
        SDL2pp::SDL sdl(SDL_INIT_VIDEO);
        SDL2pp::SDLTTF sdl_ttf;

        // load resources
        std::string fontPath = RESOURCE_PATH;
        fontPath += FONT_NAME;

        SDL2pp::Font font(fontPath.c_str(), 20);

        SDL2pp::Window window("test", 10, 10, 640, 480, SDL_WINDOW_RESIZABLE);

        SDL2pp::Renderer renderer(window, -1, 0);
        SDL2pp::Texture text(renderer, font.RenderText_Solid("Hello world!", SDL_Color{255, 255, 255, 255}));

        renderer.Clear();

        renderer.Copy(text, SDL2pp::NullOpt, SDL2pp::Point(10, 10));

        renderer.Present();

        SDL_Delay(5000);
    }
    catch (std::exception &e)
    {
        std::wcout << "Error: " << e.what() << std::endl;
    }

    return 0;
}