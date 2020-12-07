#ifndef PIECE_H
#define PIECE_H
#include <SDL2/SDL.h>
#include <string>

#include <vector>
#include <Board.h>



using namespace std;

class Piece{

    private:

        SDL_Rect origin;
        SDL_Rect destiny;
        string color;
        SDL_Point coordinate;
        vector<SDL_Rect> validSquares;

    public:

        Piece(string color, SDL_Point initialCoordinate);
        virtual ~Piece() = default;
        void restorePosition(int squareSize);
        bool isAValidCoordinate(SDL_Point coordinate, Board* board);
        vector<SDL_Rect> getValidSquares();
        void addValidSquare(SDL_Rect square);
        void resetValidSquares();
        void setCoordinate(SDL_Point coordinate);
        SDL_Point getCoordinate();
        void setDestiny(SDL_Rect destiny);
        SDL_Rect* getDestiny();
        void setOrigin(SDL_Rect origin);
        SDL_Rect* getOrigin();
        bool isWhite();

        //metodo que vai ser sobrescrito por cada peça
        virtual void showMoveOptions(Board* board) = 0;




};

#endif // PIECE_H
