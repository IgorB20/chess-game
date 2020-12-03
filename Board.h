#ifndef BOARD_H
#define BOARD_H
#include <SDL2/SDL.h>
struct Board{

    SDL_Texture* texture = nullptr;
    SDL_Surface* surface = nullptr;
    SDL_Rect destiny;
    char Board[8][8]=
        {
      'r', 'h', 'b', 'k', 'q', 'b', 'h', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'W', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'
        };
    };


#endif // BOARD_H
