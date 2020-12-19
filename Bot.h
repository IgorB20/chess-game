#ifndef BOT_H
#define BOT_H

#include <Piece.h>
#include <Board.h>

class Bot{
    public:
        bool isWhite;
        //vector<Piece*> pieces;
        Piece* selectedPiece = nullptr;
        //Board* boardCopy;

        Bot() = default;
        Bot(bool isWhite);
        void choosePiece(Board* board, vector<Piece*> pieces);
        void chooseMove(Board* board);
        //Board getBoardCopyFromPointer(Board* board);

};

#endif // BOT_H
