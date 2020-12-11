#ifndef KING_H
#define KING_H

#include <Piece.h>

class King : public Piece{
    public:
        vector<SDL_Rect> enemyPiecesValidSquares = {};
        King(string color, SDL_Point initialCoordinate, int squareSize);
        King() = default;
        ~King() = default;       
        bool isOnCheck(SDL_Point position, Board board);
        void showMoveOptions(Board board);
        //void setValidSquares(Board *board, vector<SDL_Rect> enemyPieceValidSquares);
};

#endif // KING_H
