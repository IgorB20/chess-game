#include <Board.h>

#include <iostream>

Board::Board(SDL_Renderer *renderer){
    this->destiny = {.x= 0, .y= 0, .w= 1000/2, .h= 1000/2};
    this->texture = IMG_LoadTexture(renderer,"assets/images/board.png");
    this->squareSize = 124/2;
}

void Board::update(SDL_Point oldPosition, SDL_Point newPosition){

    char pieceIdentifier = this->controlBoard[oldPosition.y][oldPosition.x];
    this->controlBoard[oldPosition.y][oldPosition.x] = '0';
    this->controlBoard[newPosition.y][newPosition.x] = pieceIdentifier;

};

SDL_Texture* Board::getTexture(){
    return this->texture;
}

SDL_Rect* Board::getDestiny(){
    return &this->destiny;
}
