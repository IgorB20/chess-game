#include <Pawn.h>
#include <iostream>

//construtor

Pawn::Pawn(string color, SDL_Point initialCoordinate) : Piece(color, initialCoordinate){
    this->setDestiny({.x=initialCoordinate.x,
                      .y=initialCoordinate.y,
                      .w=50,
                      .h=50
                     });

    if(this->isWhite()){
        this->setOrigin({.x=1070, .y=12, .w=204, .h=193});
    }else{
         this->setOrigin({.x=1070, .y=225, .w=204, .h=193});
    }
}



void Pawn::showMoveOptions(){
    std::cout << "mostrando movimentos do peao" << std::endl;
}
