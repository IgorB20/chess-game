#ifndef BISHOP_H
#define BISHOP_H

#include <Piece.h>

class Bishop : public Piece{
    public:
        Bishop(string color, SDL_Point initialCoordinate, int squareSize);
        ~Bishop() = default;
        void showMoveOptions(Board *board);
};

#endif // BISHOP_H
