#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <SDL.h>

class Display {
    int width;
    int height;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* screenTexture = nullptr;

   public:
    Display(int width_, int height_, const char* title)
        : width(width_), height(height_) {
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, &window,
                                    &renderer);
        SDL_SetWindowTitle(window, title);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        // screenTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
        // SDL_TEXTUREACCESS_STREAMING, width, height);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    ~Display() {
        SDL_DestroyTexture(screenTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    int getWidth(){
        return width;
    }

    int getHeight(){
        return height;
    }

    void update(SDL_Surface* surface) {
        if (screenTexture != nullptr) {
            SDL_DestroyTexture(screenTexture);
        }
        screenTexture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_RenderCopy(renderer, screenTexture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_Surface* createScreenSurface(){
        return SDL_CreateRGBSurface(0, width, height, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    }
};

#endif