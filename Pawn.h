#ifndef PAWN_H
#define PAWN_H
#include <Piece.h>

class Pawn : public Piece {
    public:
        Pawn(string color);
        void showMoveOptions();
};

#endif // PAWN_H
