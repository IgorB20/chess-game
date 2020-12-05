#include <PiecesInitializer.h>
#include <Pawn.h>
#include <Knight.h>

#include <iostream>

void PiecesInitializer::initAll(Board board, vector<Piece*> &pieces){
    PiecesInitializer::initPawns(board, pieces);
    PiecesInitializer::initKnights(board, pieces);
}


void PiecesInitializer::initPawns(Board board, vector<Piece*> &pieces){
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            if(board.controlBoard[i][j] == 'P'){
                pieces.push_back(new Pawn("white", {.x=j*board.squareSize,
                                                       .y=i*board.squareSize}));
            }
            if(board.controlBoard[i][j] == 'p'){
                pieces.push_back(new Pawn("black", {.x=j*board.squareSize,
                                                       .y=i*board.squareSize}));
            }
        }
    }
}

void PiecesInitializer::initKnights(Board board, vector<Piece*> &pieces){
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            if(board.controlBoard[i][j] == 'H'){
                pieces.push_back(new Knight("white", {.x=j*board.squareSize,
                                                       .y=i*board.squareSize}));
            }
            if(board.controlBoard[i][j] == 'h'){
                pieces.push_back(new Knight("black", {.x=j*board.squareSize,
                                                       .y=i*board.squareSize}));
            }
        }
    }
};
