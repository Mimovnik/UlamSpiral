#include <SDL.h>

#include <iostream>

#include "Framework.h"
#include "Spiral.h"

int main(int argc, char* argv[]) {
    const int windowWidth = 640;
    const int windowHeight = 640;
    Display display(windowWidth, windowHeight, "Ulam Spiral");
    SDL_Surface* screen = display.createScreenSurface();
    SDL_Event event;
    bool running = true;

    const Uint32 grayple = SDL_MapRGB(screen->format, 40, 42, 54);
    const Uint32 white = SDL_MapRGB(screen->format, 255, 255, 255);
    const Uint32 black = SDL_MapRGB(screen->format, 0, 0, 0);

    Spiral spiral(windowWidth / 2, windowHeight / 2, 1, white, black);
    SDL_FillRect(screen, NULL, grayple);
    
    double updatesPerFrame = 1;
    while (running) {
        Uint64 start = SDL_GetPerformanceCounter();
        // handle input
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
        for(int i = 0; i < static_cast<int>(updatesPerFrame); i ++){
        // change state
        spiral.update(display.getSize());
        // show output
        spiral.draw(screen);
        }
        updatesPerFrame +=0.05;
        display.update(screen);
        // fps
        Uint64 end = SDL_GetPerformanceCounter();
        float elapsed =
            (end - start) / static_cast<float>(SDL_GetPerformanceFrequency());
    }

    return 0;
}
