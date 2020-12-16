#ifndef ROOK_H
#define ROOK_H
#include <Piece.h>

class Rook : public Piece{
    public:
        Rook(string color, SDL_Point initialCoordinate, int squareSize);
        ~Rook() = default;
        void showMoveOptions(Board board);
};

#endif // ROOK_H
