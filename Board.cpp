#include <Board.h>

Board::Board(SDL_Renderer *renderer){
    this->destiny = {.x= 0, .y= 0, .w= 1000/2, .h= 1000/2};
    this->texture = IMG_LoadTexture(renderer,"assets/images/board.png");
}

SDL_Texture* Board::getTexture(){
    return this->texture;
}

SDL_Rect* Board::getDestiny(){
    return &this->destiny;
}
