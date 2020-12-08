#ifndef KING_H
#define KING_H

#include <Piece.h>

class King : public Piece{
    public:
        King(string color, SDL_Point initialCoordinate, int squareSize);
        ~King() = default;
        bool isThereACheck(Board *board, SDL_Point position);
        void showMoveOptions(Board *board);
};

#endif // KING_H
