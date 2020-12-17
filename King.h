#ifndef KING_H
#define KING_H

#include <Piece.h>

class King : public Piece{
    public:
        SDL_Rect castleSquare = {};
        vector<SDL_Rect> enemyPiecesValidSquares = {};
        bool isCastlePossible = false;
        int castleDirection;
        Piece* castleRook = nullptr;
        char castleRookIdentifier;

        King(string color, SDL_Point initialCoordinate, int squareSize);
        King() = default;
        ~King() = default;
        void checkCastle(vector<Piece*> pieces, Board board);
        bool isOnCheck(SDL_Point position, Board board);
        void showMoveOptions(Board board);
        //void setValidSquares(Board *board, vector<SDL_Rect> enemyPieceValidSquares);
};

#endif // KING_H
