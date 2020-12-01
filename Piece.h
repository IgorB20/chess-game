#ifndef PIECE_H
#define PIECE_H
#include <SDL2/SDL.h>
#include <string>

using namespace std;

class Piece{

    private:
        SDL_Rect destiny;
        SDL_Rect origin;
        string color;

    public:
        Piece(string color);
        void setDestiny(SDL_Rect destiny);
        SDL_Rect getDestiny();
        void setOrigin(SDL_Rect origin);
        SDL_Rect getOrigin();
        bool isWhite();

        //metodo que vai ser sobrescrito por cada peça
        virtual void showMoveOptions() = 0;

};

#endif // PIECE_H
