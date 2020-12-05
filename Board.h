#ifndef BOARD_H
#define BOARD_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Board{

    public:
        int squareSize;
        char controlBoard[8][8] = {
        {'r', 'h', 'b', 'k', 'q', 'b', 'h', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'}};
        Board(SDL_Renderer *renderer);
        SDL_Texture* getTexture();
        SDL_Rect* getDestiny();
    private:
        SDL_Texture* texture = nullptr;
        SDL_Rect destiny;
};

#endif // BOARD_H
