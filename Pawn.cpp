#include <Pawn.h>
#include <iostream>

//construtor

Pawn::Pawn(string color, SDL_Point initialCoordinate, int squareSize) : Piece(color, initialCoordinate){
    this->setDestiny({.x=initialCoordinate.x * squareSize,
                      .y=initialCoordinate.y* squareSize,
                      .w=50,
                      .h=50
                     });

    if(this->isWhite()){
        this->setOrigin({.x=1070, .y=12, .w=204, .h=193});
    }else{
         this->setOrigin({.x=1070, .y=225, .w=204, .h=193});
    }
}

void Pawn::showMoveOptions(Board* board){

    vector<SDL_Point> posssiblePositions;
    int squareSize = board->squareSize;

    int linha = this->getCoordinate().y;
    int coluna = this->getCoordinate().x;

    int move1 = 1;
    int move2 = 2;

    if(this->isWhite()){
        move1 = -1;
        move2 = -2;
    }
    if(isFirstMove == true){
        posssiblePositions = {
            {.x=coluna, .y=linha+move1},
            {.x=coluna, .y=linha+move2},
        };
        isFirstMove = false;
        if(board->controlBoard[linha+move1][coluna+move1] != '0'  or  board->controlBoard[linha+move1][coluna-move1] != '0'){
            posssiblePositions = {
                        {.x=coluna, .y=linha+move1},
                        {.x=coluna, .y=linha+move2},
                        {.x=coluna+move1 , .y=linha+move1},
                        {.x=coluna+move1 , .y=linha-move1},
                    };
        }
    }

    for(SDL_Point position : posssiblePositions){
        if(this->isAValidCoordinate({.x=position.x, .y=position.y}, board)){
           int newY = (position.y)*squareSize;
           int newX = (position.x)*squareSize;
           this->addValidSquare({.x = newX, .y = newY, .w=squareSize, .h=squareSize});
         }
    }



}
