#ifndef BOARD_H
#define BOARD_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Board{

    public:
        int squareSize;
        char controlBoard[8][8] = {
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', 'q', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', 'B', '0', '0'},
        {'0', '0', '0', '0', 'K', '0', '0', 'R'},};
/*
        char controlBoard[8][8] = {
        {'r', 'h', 'b', 'k', 'q', 'b', 'h', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'}};*/
/*
        char controlBoard[8][8] = {
        {'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'h', 'b', 'k', 'q', 'b', 'h', 'r'}};*/

        Board(SDL_Renderer *renderer);
        SDL_Texture* getTexture();
        SDL_Rect* getDestiny();
        void update(SDL_Point oldPosition, SDL_Point newPosition);
    private:
        SDL_Texture* texture = nullptr;
        SDL_Rect destiny;
};


#endif // BOARD_H
