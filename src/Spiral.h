#ifndef SPIRAL_H
#define SPIRAL_H

#include <SDL.h>
#include <math.h>

class Spiral {
    int x;
    int y;
    int dir = -1;
    int dirCount = 0;
    int stepCount = 0;
    int sideLen = 1;
    int stepSize;
    Uint32 compositColor;
    Uint32 primeColor;

    void drawPixel(SDL_Surface* surface, int x, int y, Uint32 color) {
        if (y >= 0 && y <= surface->h && x >= 0 && x <= surface->w) {
            SDL_LockSurface(surface);
            int bpp = surface->format->BytesPerPixel;
            Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;
            *(Uint32*)p = color;
            SDL_UnlockSurface(surface);
        }
    };

    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

   public:
    Spiral(int startX, int startY, int stepSize, Uint32 compositColor, Uint32 primeColor) {
        this->x = startX;
        this->y = startY;
        this->stepSize = stepSize;
        this->compositColor = compositColor;
        this->primeColor = primeColor;
    }

    void update(int pixelCount) {
        if (stepCount > pixelCount) {
            return;
        }
        switch (dir) {
            case 0:
                x+=stepSize;
                break;
            case 1:
                y-=stepSize;
                break;
            case 2:
                x-=stepSize;
                break;
            case 3:
                y+=stepSize;
                break;
                default:
                break;
        }
        if (stepCount % sideLen == 0) {
            dir++;
            dir %= 4;
            dirCount++;
            if (dirCount % 2 == 0) {
                sideLen++;
            }
        }
        stepCount++;
    }

    void draw(SDL_Surface* surface) {
        if (isPrime(stepCount)) {
            drawPixel(surface, x, y, primeColor);
        } else {
            drawPixel(surface, x, y, compositColor);
        }
        if(stepCount == 1){
            drawPixel(surface, x, y, SDL_MapRGB(surface->format, 255,0,0));

        }
    }
};

#endif