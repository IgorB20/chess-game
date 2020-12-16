#include <PiecesInitializer.h>
#include <Pawn.h>
#include <Knight.h>
#include <Rook.h>
#include <Bishop.h>
#include <Queen.h>


#include <iostream>

void PiecesInitializer::initAll(Board board, vector<Piece*> &pieces){
    PiecesInitializer::initPawns(board, pieces);
    PiecesInitializer::initKnights(board, pieces);
    PiecesInitializer::initRooks(board, pieces);
     PiecesInitializer::initBishops(board, pieces);
     PiecesInitializer::initQueens(board, pieces);

}


void PiecesInitializer::initPawns(Board board, vector<Piece*> &pieces){
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            if(board.controlBoard[i][j] == 'P'){
                pieces.push_back(new Pawn("white", {.x=j,
                                                       .y=i},board.squareSize));
            }
            if(board.controlBoard[i][j] == 'p'){
                pieces.push_back(new Pawn("black", {.x=j,
                                                       .y=i},board.squareSize));
            }
        }
    }
}

void PiecesInitializer::initKnights(Board board, vector<Piece*> &pieces){
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            if(board.controlBoard[i][j] == 'H'){
                pieces.push_back(new Knight("white", {.x=j,
                                                       .y=i}, board.squareSize));
            }
            if(board.controlBoard[i][j] == 'h'){
                pieces.push_back(new Knight("black", {.x=j, .y=i}, board.squareSize));
            }
        }
    }
};


void PiecesInitializer::initRooks(Board board, vector<Piece*> &pieces){
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            if(board.controlBoard[i][j] == 'R'){
                pieces.push_back(new Rook("white", {.x=j,
                                                       .y=i}, board.squareSize));
            }
            if(board.controlBoard[i][j] == 'r'){
                pieces.push_back(new Rook("black", {.x=j, .y=i}, board.squareSize));
            }
        }
    }
};

void PiecesInitializer::initBishops(Board board, vector<Piece*> &pieces){
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            if(board.controlBoard[i][j] == 'B'){
                pieces.push_back(new Bishop("white", {.x=j,
                                                       .y=i}, board.squareSize));
            }
            if(board.controlBoard[i][j] == 'b'){
                pieces.push_back(new Bishop("black", {.x=j, .y=i}, board.squareSize));
            }
        }
    }
};

void PiecesInitializer::initQueens(Board board, vector<Piece*> &pieces){
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            if(board.controlBoard[i][j] == 'Q'){
                pieces.push_back(new Queen("white", {.x=j,
                                                       .y=i}, board.squareSize));
            }
            if(board.controlBoard[i][j] == 'q'){
                pieces.push_back(new Queen("black", {.x=j, .y=i}, board.squareSize));
            }
        }
    }
};
