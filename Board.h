#ifndef BOARD_H
#define BOARD_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Board{

    public:
        int squareSize;
        /*
        char controlBoard[8][8] = {
        {'R', '0', '0', 'K', '0', '0', '0', 'R'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'r', '0', '0', 'k', '0', '0', '0', 'r'},};*/

        char controlBoard[8][8];
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

        Board() = default;
        Board(SDL_Renderer *renderer);
        SDL_Texture* getTexture();
        SDL_Rect* getDestiny();
        void update(SDL_Point oldPosition, SDL_Point newPosition);
        char columnNames[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
        char rowNames[8] = {'8', '7', '6', '5', '4', '3', '2', '1'};
    private:
        SDL_Texture* texture = nullptr;
        SDL_Rect destiny;
};


#endif // BOARD_H
