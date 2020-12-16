#include <Pawn.h>
#include <iostream>

//construtor

Pawn::Pawn(string color, SDL_Point initialCoordinate, int squareSize) : Piece(color, initialCoordinate){
    this->setDestiny({.x=initialCoordinate.x * squareSize,
                      .y=initialCoordinate.y* squareSize,
                      .w=50,
                      .h=50
                     });

    if(this->isWhite()){
        this->setOrigin({.x=1070, .y=12, .w=204, .h=193});
    }else{
         this->setOrigin({.x=1070, .y=225, .w=204, .h=193});
    }
}

void Pawn::showMoveOptions(Board board){

    int squareSize = board.squareSize;

    int linha = this->getCoordinate().y;
    int coluna = this->getCoordinate().x;

    this->checkDiagonalsCaptures(board);

    if(this->isWhite()){

        if(this->isFirstMove){
            if(!this->isAEnemyPiece({.x = coluna, .y = linha-1}, board)){
                this->addValidSquare({.x = coluna*squareSize, .y = (linha-1)*squareSize, .w=squareSize, .h=squareSize});
            }

            if(!this->isAEnemyPiece({.x = coluna, .y = linha-2}, board)){
                this->addValidSquare({.x = coluna*squareSize, .y = (linha-2)*squareSize, .w=squareSize, .h=squareSize});
            }


        }else{
           if(!this->isAEnemyPiece({.x = coluna, .y = linha-1}, board))
                this->addValidSquare({.x = coluna*squareSize, .y = (linha-1)*squareSize, .w=squareSize, .h=squareSize});
        }
    }

    if(!this->isWhite()){
        if(this->isFirstMove){
            if(!this->isAEnemyPiece({.x = coluna, .y = linha+1}, board)){
                this->addValidSquare({.x = coluna*squareSize, .y = (linha+1)*squareSize, .w=squareSize, .h=squareSize});
            }

            if(!this->isAEnemyPiece({.x = coluna, .y = linha+2}, board)){
                this->addValidSquare({.x = coluna*squareSize, .y = (linha+2)*squareSize, .w=squareSize, .h=squareSize});
            }


        }else{
           if(!this->isAEnemyPiece({.x = coluna, .y = linha+1}, board))
                this->addValidSquare({.x = coluna*squareSize, .y = (linha+1)*squareSize, .w=squareSize, .h=squareSize});
        }
    }

}

void Pawn::checkDiagonalsCaptures(Board board){
        int squareSize = board.squareSize;
    int linha = this->getCoordinate().y;
    int coluna = this->getCoordinate().x;

    if(this->isWhite()){
        if(this->isAEnemyPiece({.x = coluna+1, .y = linha-1}, board)){
            this->addValidSquare({.x = (coluna+1)*squareSize, .y = (linha-1)*squareSize, .w=squareSize, .h=squareSize});
        }
        if(this->isAEnemyPiece({.x = coluna-1, .y = linha-1}, board)){
            this->addValidSquare({.x = (coluna-1)*squareSize, .y = (linha-1)*squareSize, .w=squareSize, .h=squareSize});
        }
    }

    if(!this->isWhite()){
        if(this->isAEnemyPiece({.x = coluna+1, .y = linha+1}, board)){
            this->addValidSquare({.x = (coluna+1)*squareSize, .y = (linha+1)*squareSize, .w=squareSize, .h=squareSize});
        }
        if(this->isAEnemyPiece({.x = coluna-1, .y = linha+1}, board)){
            this->addValidSquare({.x = (coluna-1)*squareSize, .y = (linha+1)*squareSize, .w=squareSize, .h=squareSize});
        }
    }



};
