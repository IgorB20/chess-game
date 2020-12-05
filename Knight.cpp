#include <Knight.h>

#include <iostream>

//construtor

Knight::Knight(string color, SDL_Point initialCoordinate) : Piece(color, initialCoordinate){
    this->setDestiny({.x=initialCoordinate.x,
                      .y=initialCoordinate.y,
                      .w=50,
                      .h=50
                     });

    if(this->isWhite()){
        this->setOrigin({.x=654, .y=12, .w=204, .h=193});
    }else{
         this->setOrigin({.x=654, .y=225, .w=204, .h=193});
    }
}



void Knight::showMoveOptions(){
    std::cout << "mostrando movimentos do cavalo" << std::endl;
}
