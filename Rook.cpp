#include <Rook.h>
#include <iostream>


void Rook::showMoveOptions(Board *board){
    int squareSize = board->squareSize;

    vector<SDL_Point> posssibleDirections = {
        {.x=0, .y=-1},
        {.x=0, .y=+1},
        {.x=+1, .y=0},
        {.x=-1, .y=0},
    };

    bool stop = false;
    int linha = this->getCoordinate().y;
    int coluna = this->getCoordinate().x;

    for(SDL_Point direction : posssibleDirections){
        while(!stop){
            linha += direction.y;
            coluna += direction.x;
            if(this->isAValidCoordinate({.x=coluna, .y=linha}, board)){

                int newY = (linha)*squareSize;
                int newX = (coluna)*squareSize;
                this->addValidSquare({.x = newX, .y = newY, .w=squareSize, .h=squareSize});
            }else{
                stop = true;
            }
        }

        stop = false;
        linha = this->getCoordinate().y;
        coluna = this->getCoordinate().x;
    }
}
