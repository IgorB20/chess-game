#ifndef KNIGHT_H
#define KNIGHT_H
#include <Piece.h>

class Knight : public Piece{
    public:
        Knight(string color, SDL_Point initialCoordinate, int squareSize);
        ~Knight() = default;
        void showMoveOptions(Board board);
};

#endif // KNIGHT_H
