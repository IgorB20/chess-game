#include <Piece.h>

#include<iostream>

//construtor
Piece::Piece(string color, SDL_Point initialCoordinate){
    this->color = color;
    this->coordinate = initialCoordinate;
    this->validSquares = {};

}

void Piece::restorePosition(int squareSize){
    this->getDestiny()->x = this->getCoordinate().x*squareSize;
    this->getDestiny()->y = this->getCoordinate().y*squareSize;
};

vector<SDL_Rect> Piece::getValidSquares(){
    return this->validSquares;
};

void Piece::addValidSquare(SDL_Rect square){
    this->validSquares.push_back(square);
};

void Piece::resetValidSquares(){
    this->validSquares.clear();
};


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

SDL_Point Piece::getCoordinate(){
    return this->coordinate;
};
