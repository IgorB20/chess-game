#include <Piece.h>

#include<iostream>

//construtor
Piece::Piece(string color, SDL_Point initialCoordinate){
    this->color = color;
    this->coordinate = initialCoordinate;
}


bool Piece::isWhite(){
    if(this->color == "white") return true;
    else return false;
}

void Piece::setDestiny(SDL_Rect destiny){
    this->destiny = destiny;
}

SDL_Rect* Piece::getDestiny(){
    return &this->destiny;
}

void Piece::setOrigin(SDL_Rect origin){
    this->origin = origin;
}

SDL_Rect* Piece::getOrigin(){
    return &this->origin;
}

void Piece::setCoordinate(SDL_Point coordinate){
    this->coordinate = coordinate;
};

SDL_Point* Piece::getCoordinate(){
    return &this->coordinate;
};
