#include <Knight.h>

#include <iostream>

//construtor

Knight::Knight(string color, SDL_Point initialCoordinate, int squareSize) : Piece(color, initialCoordinate){
    this->setDestiny({.x=initialCoordinate.x*squareSize,
                      .y=initialCoordinate.y*squareSize,
                      .w=50,
                      .h=50
                     });

    if(this->isWhite()){
        this->setOrigin({.x=654, .y=12, .w=204, .h=193});
    }else{
         this->setOrigin({.x=654, .y=225, .w=204, .h=193});
    }
}



void Knight::showMoveOptions(Board *board){

    int squareSize = board->squareSize;

    int linha = this->getCoordinate().y;
    int coluna = this->getCoordinate().x;

    cout << linha << ", " << coluna << endl;

    //cima
      if(linha - 2 >= 0){
          if( coluna + 1 <= 7 ){
               //board->controlBoard[linha-2][coluna+1] = 'X';
              int newY = (linha-2)*squareSize;
              int newX = (coluna+1)*squareSize;
              this->addValidSquare({.x = newX, .y = newY, .w=squareSize, .h=squareSize});
          }
          if( coluna - 1 >= 0 ){
               //board->controlBoard[linha-2][coluna-1] = 'X';
              int newY = (linha-2)*squareSize;
              int newX = (coluna-1)*squareSize;
              this->addValidSquare({.x = newX, .y = newY, .w=squareSize, .h=squareSize});
          }


      }


    //direita

    if(coluna + 2 <= 7){
        if( linha + 1 <= 7 ){
           //controlBoard[linha+1][coluna+2] = 'X';
            int newY = (linha+1)*squareSize;
            int newX = (coluna+2)*squareSize;
            this->addValidSquare({.x = newX, .y = newY, .w=squareSize, .h=squareSize});
        }

        if( linha - 1 >= 0 ){
           //controlBoard[linha-1][coluna+2] = 'X';
            int newY = (linha-1)*squareSize;
            int newX = (coluna+2)*squareSize;
            this->addValidSquare({.x = newX, .y = newY, .w=squareSize, .h=squareSize});
        }

    }

    //BAIXO
    if(linha + 2 >= 0){
        if( coluna + 1 <= 7 ){

            int newY = (linha+2)*squareSize;
            int newX = (coluna+1)*squareSize;
            this->addValidSquare({.x = newX, .y = newY, .w=squareSize, .h=squareSize});
        }
        if( coluna - 1 >= 0 ){

            int newY = (linha+2)*squareSize;
            int newX = (coluna-1)*squareSize;
            this->addValidSquare({.x = newX, .y = newY, .w=squareSize, .h=squareSize});
        }
    }


    //esquerda
    if(coluna - 2 <= 7){
        if( linha + 1 <= 7 ){
           //controlBoard[linha+1][coluna+2] = 'X';
            int newY = (linha+1)*squareSize;
            int newX = (coluna-2)*squareSize;
            this->addValidSquare({.x = newX, .y = newY, .w=squareSize, .h=squareSize});
        }

        if( linha - 1 >= 0 ){
           //controlBoard[linha-1][coluna+2] = 'X';
            int newY = (linha-1)*squareSize;
            int newX = (coluna-2)*squareSize;
            this->addValidSquare({.x = newX, .y = newY, .w=squareSize, .h=squareSize});
        }

    }

}
