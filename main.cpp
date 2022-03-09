#include <SDL.h>

#include <iostream>

#include "src/Framework.h"

int main(int argc, char* argv[]) {
    Display display(640, 480, "Ulam Spiral");
    SDL_Surface* screen = display.createScreenSurface();
    SDL_Event event;
    bool running = true;

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
        // change state

        // show output
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 40, 42, 54));
        display.update(screen);

        // fps
        Uint64 end = SDL_GetPerformanceCounter();
        float elapsed =
            (end - start) / static_cast<float>(SDL_GetPerformanceFrequency());
    }

    return 0;
}
