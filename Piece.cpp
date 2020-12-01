#include <Piece.h>

//construtor
Piece::Piece(string color){
    this->color = color;
}

bool Piece::isWhite(){
    if(this->color == "white") return true;
    else return false;
}

void Piece::setDestiny(SDL_Rect destiny){
    this->destiny = destiny;
}

SDL_Rect Piece::getDestiny(){
    return this->destiny;
}

void Piece::setOrigin(SDL_Rect origin){
    this->origin = origin;
}

SDL_Rect Piece::getOrigin(){
    return this->origin;
}
