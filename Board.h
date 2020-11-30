#ifndef BOARD_H
#define BOARD_H
#include <SDL2/SDL.h>
struct Board{

    SDL_Texture* texture = nullptr;
    SDL_Surface* surface = nullptr;
    SDL_Rect destiny;
};

#endif // BOARD_H
