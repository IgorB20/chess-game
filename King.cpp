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
        this->castleRookIdentifier = 'R';
        if(initialCoordinate.y == 7) this->castleDirection = 1;
        if(initialCoordinate.y == 0) this->castleDirection = -1;
    }else{
         this->setOrigin({.x=6, .y=225, .w=204, .h=193});
        this->castleRookIdentifier = 'r';
        if(initialCoordinate.y == 7) this->castleDirection = -1;
        if(initialCoordinate.y == 0) this->castleDirection = 1;
    }


}



void King::showMoveOptions(Board board){
    //cout <<"size: " << this->enemyPiecesValidSquares.size() << endl;
    int squareSize = board.squareSize;

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
                    !this->isOnCheck({.x=coluna, .y=linha}, board)){

                int newY = (linha)*squareSize;
                int newX = (coluna)*squareSize;
                this->addValidSquare({.x = newX, .y = newY, .w=squareSize, .h=squareSize});
            }

        linha = this->getCoordinate().y;
        coluna = this->getCoordinate().x;
    }
}



bool King::isOnCheck(SDL_Point position, Board board){

   int squareSize = board.squareSize;
   int isCheck = false;

   for(SDL_Rect enemyPieceValidSquare : this->enemyPiecesValidSquares){
        if(position.x*squareSize == enemyPieceValidSquare.x &&
                position.y*squareSize == enemyPieceValidSquare.y){
            isCheck = true;
            break;
        }
   }

   return isCheck;

};

void King::checkCastle(vector<Piece*> pieces, Board board){
    this->castleRook = nullptr;
    this->isCastlePossible = false;
    this->castleSquare = {};

    int linha = this->getCoordinate().y;
    int coluna = this->getCoordinate().x + (2*this->castleDirection);

    if(!this->isFirstMove)  return;
    if(this->isOnCheck(this->getCoordinate(), board)) return;
    if(board.controlBoard[linha][coluna] != '0') return;
    if(board.controlBoard[linha][coluna-(1*this->castleDirection)] != '0') return;

    int teste = false;
    for(Piece* piece : pieces){
        if(this->isAEnemyPiece(piece->getCoordinate(), board)){
            piece->showMoveOptions(board);
            for(SDL_Rect validSquare : piece->getValidSquares()){
                if((validSquare.y/board.squareSize == linha && validSquare.x/board.squareSize == coluna) ||
                 (validSquare.y/board.squareSize == linha && validSquare.x/board.squareSize == coluna-(1*this->castleDirection))
                ){
                    teste = true;

                }
            }

           piece->resetValidSquares();
           if(teste) break;
        }

        if(piece->getCoordinate().x == (coluna+(1*this->castleDirection)) &&
                piece->getCoordinate().y == linha &&
                    piece->isFirstMove){
            if(board.controlBoard[linha][coluna+(1*this->castleDirection)] == this->castleRookIdentifier){
                cout << "Voce pode fazer o roque" << endl;
                this->castleRook = piece;
                this->isCastlePossible = true;
                this->castleSquare = {
                            .x =(coluna)*board.squareSize,
                            .y= linha*board.squareSize,
                            .w=50,
                            .h=50
                  };

            }else{
                isCastlePossible = false;
            }
        }
    }


};
