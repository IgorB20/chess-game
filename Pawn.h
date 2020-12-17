#ifndef PAWN_H
#define PAWN_H
#include <Piece.h>

class Pawn : public Piece {
    public:
        int moveDirection;

        Pawn(string color, SDL_Point initialCoordinate, int squareSize);
        ~Pawn() = default;
        void checkDiagonalsCaptures(Board board);
        void showMoveOptions(Board board);

};

#endif // PAWN_H
