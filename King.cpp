#include <King.h>

#include <iostream>

#include <math.h>

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

            if(this->isAValidCoordinate({.x=coluna, .y=linha}, board) &&
                !this->isThereACheck(board, {.x=coluna, .y=linha})){

                int newY = (linha)*squareSize;
                int newX = (coluna)*squareSize;
                this->addValidSquare({.x = newX, .y = newY, .w=squareSize, .h=squareSize});
            }

        linha = this->getCoordinate().y;
        coluna = this->getCoordinate().x;
    }
}

bool King::isThereACheck(Board *board, SDL_Point position){

    //horizontais
     for(int j=0; j < 8; j++){

             if(board->controlBoard[position.y][j] == 'q'){
                if( fabs(this->getCoordinate().x - j) <= 1 && j == position.x){
                    return false;
                }else{
                     return true;
                }
             }
     }

     //verticais
     for(int i=0; i < 8; i++){

             if(board->controlBoard[i][position.x] == 'q'){
                if( fabs(this->getCoordinate().y - i) <= 1 && i == position.y){
                    return false;
                }else{
                     return true;
                }
             }
     }

     return false;

};
