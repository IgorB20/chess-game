#include <Piece.h>

#include<iostream>

//construtor
Piece::Piece(string color, SDL_Point initialCoordinate){
    this->color = color;
    this->coordinate = initialCoordinate;
    this->validSquares = {};

}

bool Piece::isAValidCoordinate(SDL_Point coordinate, Board* board){
    if(coordinate.x >=0 && coordinate.x < 8 && coordinate.y >=0 && coordinate.y < 8){
        if(this->isAEnemyPiece(coordinate, board) ||
                board->controlBoard[coordinate.y][coordinate.x] == '0'){
            return true;
        }
    }


    return false;
};

bool Piece::isAEnemyPiece(SDL_Point coordinate, Board* board){
    if((this->isWhite() && !isupper(board->controlBoard[coordinate.y][coordinate.x]) && board->controlBoard[coordinate.y][coordinate.x] != '0') ||
            (!this->isWhite() && isupper(board->controlBoard[coordinate.y][coordinate.x]))){
        return true;
    }

    return false;
};

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
