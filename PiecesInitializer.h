#ifndef PIECESINITIALIZER_H
#define PIECESINITIALIZER_H

#include <Board.h>
#include <Piece.h>
#include <vector>

class PiecesInitializer{
    public:
        static void initAll(Board board, vector<Piece*> &pieces);

    private:
      static void initPawns(Board board, vector<Piece*> &pieces);
      static void initKnights(Board board, vector<Piece*> &pieces);
};

#endif // PIECESINITIALIZER_H
