#ifndef QUEEN_H
#define QUEEN_H

#include <Piece.h>

class Queen : public Piece{
    public:
        Queen(string color, SDL_Point initialCoordinate, int squareSize);
        ~Queen() = default;
        void showMoveOptions(Board board);
};

#endif // QUEEN_H
