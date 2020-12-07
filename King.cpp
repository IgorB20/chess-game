#include <King.h>

#include <iostream>

King::King(string color, SDL_Point initialCoordinate, int squareSize) : Piece(color, initialCoordinate){
    this->setDestiny({.x=initialCoordinate.x*squareSize,
                      .y=initialCoordinate.y*squareSize,
                      .w=50,
                      .h=50
                     });

    if(this->isWhite()){
        this->setOrigin({.x=6, .y=12, .w=204, .h=193});
    }else{
         this->setOrigin({.x=6, .y=225, .w=204, .h=193});
    }
}



void King::showMoveOptions(Board *board){
    int squareSize = board->squareSize;

    vector<SDL_Point> posssibleDirections = {
        {.x=0, .y=-1},
        {.x=0, .y=+1},
        {.x=+1, .y=0},
        {.x=-1, .y=0},
        {.x=+1, .y=-1},
        {.x=-1, .y=-1},
        {.x=-1, .y=+1},
        {.x=+1, .y=+1},
    };


    int linha = this->getCoordinate().y;
    int coluna = this->getCoordinate().x;

    for(SDL_Point direction : posssibleDirections){

            linha += direction.y;
            coluna += direction.x;
            if(this->isAValidCoordinate({.x=coluna, .y=linha}, board)){

                int newY = (linha)*squareSize;
                int newX = (coluna)*squareSize;
                this->addValidSquare({.x = newX, .y = newY, .w=squareSize, .h=squareSize});
            }

        linha = this->getCoordinate().y;
        coluna = this->getCoordinate().x;
    }
}
