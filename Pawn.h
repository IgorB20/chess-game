#ifndef PAWN_H
#define PAWN_H
#include <Piece.h>

class Pawn : public Piece {
    public:
        bool isFirstMove = true;
        Pawn(string color, SDL_Point initialCoordinate, int squareSize);
        ~Pawn() = default;
        void showMoveOptions(Board board);

};

#endif // PAWN_H
