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

        bool isFirstMove;

        Piece(string color, SDL_Point initialCoordinate);
        Piece() = default;
        virtual ~Piece() = default;
        void updatePosition(SDL_Rect position);
        void restorePosition(int squareSize);
        bool isAEnemyPiece(SDL_Point coordinate, Board board);
        bool isAValidCoordinate(SDL_Point coordinate, Board board);
        vector<SDL_Rect> getValidSquares();
         void setValidSquares(vector<SDL_Rect> squares);
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
        virtual void showMoveOptions(Board board) = 0;




};

#endif // PIECE_H
