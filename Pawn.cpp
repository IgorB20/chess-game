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

void Pawn::showMoveOptions(Board* board){
    int i = 1;
    int j = 1;

    if(board.Board[i][j] == 'p' && isFirstMove == true)
        {
         board.Board[i+1][j] = 'x';
         board.Board[i+2][j] = 'x';
         isFirstMove = false;
        }   else
        {
         board.Board[i+1][j] = 'x';
        }


    if(board.Board[i][j] == 'P' && isFirstMove == true)
        {
         board.Board[i-1][j] = 'x';
         board.Board[i-2][j] = 'x';
         isFirstMove = false;
    }   else
    {
     board.Board[i-1][j] = 'x';
    }


    for (i = 0;i <= 7; i++)
    {
        for(j = 0; j <= 7; j++)
        {
            std::cout << board.Board[i][j];
        }
        std::cout << std::endl;
    }

}
