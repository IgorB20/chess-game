#include <Bot.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Bot::Bot(bool isWhite){
    this->isWhite = isWhite;
}

void Bot::choosePiece(Board* board, vector<Piece*> pieces){
    srand(time(0));

    vector<Piece*> botPieces;
    for(Piece* piece : pieces){
        if((piece->isWhite() && this->isWhite) || (!piece->isWhite() && !this->isWhite)){
            botPieces.push_back(piece);
        }
    }

    int randomNumber = rand() % (botPieces.size());
    cout << randomNumber << endl;

    Board boardCopy;
    boardCopy.squareSize = board->squareSize;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            boardCopy.controlBoard[i][j] = board->controlBoard[i][j];
        }
    }


    this->selectedPiece = botPieces[randomNumber];
    this->selectedPiece->showMoveOptions(boardCopy);

    while(this->selectedPiece->getValidSquares().size() == 0){
        this->selectedPiece->resetValidSquares();
        randomNumber = rand() % (botPieces.size());
        this->selectedPiece = botPieces[randomNumber];
        this->selectedPiece->showMoveOptions(boardCopy);
    }

};

void Bot::chooseMove(Board* board){
    srand(time(0));
    vector<SDL_Rect> validSquares = this->selectedPiece->getValidSquares();
    int randomNumber = rand() % (validSquares.size());
    this->selectedPiece->updatePosition({
                                            .x=validSquares[randomNumber].x,
                                             .y=validSquares[randomNumber].y,
                                        });


    this->selectedPiece->setCoordinate({.x =validSquares[randomNumber].x/board->squareSize,
                                           .y=validSquares[randomNumber].y/board->squareSize
                                         });

}


