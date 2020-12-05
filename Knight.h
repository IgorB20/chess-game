#ifndef KNIGHT_H
#define KNIGHT_H
#include <Piece.h>

class Knight : public Piece{
    public:
        Knight(string color, SDL_Point initialCoordinate);
        ~Knight() = default;
        void showMoveOptions();
};

#endif // KNIGHT_H
