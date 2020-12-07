#include <Knight.h>

#include <iostream>

//construtor

Knight::Knight(string color, SDL_Point initialCoordinate, int squareSize) : Piece(color, initialCoordinate){
    this->setDestiny({.x=initialCoordinate.x*squareSize,
                      .y=initialCoordinate.y*squareSize,
                      .w=50,
                      .h=50
                     });

    if(this->isWhite()){
        this->setOrigin({.x=654, .y=12, .w=204, .h=193});
    }else{
         this->setOrigin({.x=654, .y=225, .w=204, .h=193});
    }
}



void Knight::showMoveOptions(Board *board){

    int squareSize = board->squareSize;

    int linha = this->getCoordinate().y;
    int coluna = this->getCoordinate().x;

    vector<SDL_Point> posssiblePositions = {
        //cima
        {.x=coluna+1, .y=linha-2},
        {.x=coluna-1, .y=linha-2},
        //direita
        {.x=coluna+2, .y=linha+1},
        {.x=coluna+2, .y=linha-1},
        //baixo
        {.x=coluna+1, .y=linha+2},
        {.x=coluna-1, .y=linha+2},
        //esquerda
        {.x=coluna-2, .y=linha+1},
        {.x=coluna-2, .y=linha-1},
    };

    for(SDL_Point position : posssiblePositions){
        if(this->isAValidCoordinate({.x=position.x, .y=position.y}, board)){
           int newY = (position.y)*squareSize;
           int newX = (position.x)*squareSize;
           this->addValidSquare({.x = newX, .y = newY, .w=squareSize, .h=squareSize});
         }
    }
}
