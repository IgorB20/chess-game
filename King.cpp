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

     int peca_frente_y = -1;
     int rainha_y = -1;
     bool teste = false;
     //verticais pra cima do rei
     for(int i=position.y; i>=0; i--){

         if(board->controlBoard[i][position.x] != 'q' &&
                board->controlBoard[i][position.x] != '0'){
                peca_frente_y = i;
         }
         if(board->controlBoard[i][position.x] == 'q'){
             rainha_y = i;
            if( fabs(this->getCoordinate().y - i) <= 1 && i == position.y){
                teste = false;
            }else{
                 teste = true;
                 //return true;

            }
         }
     }

     if(peca_frente_y > -1)
         if(fabs(position.y - peca_frente_y) < fabs(position.y - rainha_y)){
             teste =  false;
         }

     if(teste) return teste;


     peca_frente_y = -1;
     rainha_y = -1;
     //verticais pra baixo do rei
     for(int i=position.y; i<8; i++){

         if(board->controlBoard[i][position.x] != 'q' &&
                board->controlBoard[i][position.x] != '0'){
                peca_frente_y = i;
         }
         if(board->controlBoard[i][position.x] == 'q'){
             rainha_y = i;
            if( fabs(this->getCoordinate().y - i) <= 1 && i == position.y){
                teste = false;
            }else{
                 teste = true;
                //return true;
            }
         }
     }

    if(peca_frente_y > -1)
         if(fabs(position.y - peca_frente_y) < fabs(position.y - rainha_y)){
             teste =  false;
         }

    if(teste) return teste;


    peca_frente_y = -1;
    rainha_y = -1;
    //horizontais pra direita do rei
    for(int i=position.x; i<8; i++){

        if(board->controlBoard[position.y][i] != 'q' &&
               board->controlBoard[position.y][i] != '0'){
               peca_frente_y = i;
        }
        if(board->controlBoard[position.y][i] == 'q'){
            rainha_y = i;
           if( fabs(this->getCoordinate().y - i) <= 1 && i == position.x){
               teste = false;
           }else{
                teste = true;
               //return true;
           }
        }
    }

   if(peca_frente_y > -1)
        if(fabs(position.y - peca_frente_y) < fabs(position.y - rainha_y)){
            teste =  false;
        }




     return teste;


     //horizontais
     /*
      for(int j=0; j < 8; j++){

              if(board->controlBoard[position.y][j] == 'q'){
                 if( fabs(this->getCoordinate().x - j) <= 1 && j == position.x){
                     return false;
                 }else{
                      return true;
                 }
              }
      }*/

};
