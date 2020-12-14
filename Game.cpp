#include <Game.h>
#include <Pawn.h>
#include <Knight.h>
#include <iostream>

#include <PiecesInitializer.h>

#include <King.h>

Game::Game(){
    this->init();

    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            if(this->board.controlBoard[i][j] == 'K'){
                this->kings.push_back( new King("white", {.x=j, .y=i},this->board.squareSize) );
            }

            if(this->board.controlBoard[i][j] == 'k'){
                this->kings.push_back( new King("black", {.x=j, .y=i},this->board.squareSize) );
            }
        }
    }

    for(King* king : this->kings){
        this->pieces.push_back(king);
    }


}

void Game::init(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        cout << SDL_GetError() << endl;

    this->running = true;
    this->initWindow();
    this->renderer = SDL_CreateRenderer(this->getWindow(), -1, 0);
    this->board = {this->getRenderer()};
    this->piecesTextures = IMG_LoadTexture(this->getRenderer(), "assets/images/pieces.png");

    PiecesInitializer::initAll(this->board, this->pieces);
}

void Game::initWindow(){
   this->window = SDL_CreateWindow("Chess",
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    500, 500,
                                    0);
}


void Game::setSelectedPiece(Piece* piece){
    this->selectedPiece = piece;
};

Piece* Game::getSelectedPiece(){
    return this->selectedPiece;
};

SDL_Renderer* Game::getRenderer(){
    return this->renderer;
};

SDL_Window* Game::getWindow(){
    return this->window;
};

bool Game::isRunning(){
    return this->running;
}

void Game::setRunning(bool running){
    this->running = running;
};

Board* Game::getBoard(){
    return &this->board;
};

void Game::renderBoard(){
 SDL_RenderCopy(this->getRenderer(),  this->getBoard()->getTexture(), NULL, this->getBoard()->getDestiny());
};

void Game::checkChecks(){

    King * king = nullptr;
    for(King* k : this->kings){
        if(this->getSelectedPiece() == k){
               king = k;
        }
    }

        if(king){
            /*
            for(Piece* piece : this->pieces){
                if( piece != king &&
                     king->isAEnemyPiece(piece->getCoordinate(), this->board )){

                    Board boardCopy = this->board;
                    boardCopy.controlBoard[king->getCoordinate().y][king->getCoordinate().x] = '0';

                    piece->showMoveOptions(boardCopy);
                    for(SDL_Rect validSquare : piece->getValidSquares()){
                        king->enemyPiecesValidSquares.push_back(validSquare);
                    }
                    piece->resetValidSquares();
                }
            }*/
            king->showMoveOptions(this->board);

            //verify check after capture
            Board boardCopy = this->board;

            for(SDL_Rect validSquare : king->getValidSquares()){

                for(Piece* piece : this->pieces){

                    if(piece != king && king->isAEnemyPiece(piece->getCoordinate(), boardCopy )){
                        boardCopy.controlBoard[king->getCoordinate().y][king->getCoordinate().x] = '0';

                        if(king->isWhite()) boardCopy.controlBoard[validSquare.y/this->board.squareSize][validSquare.x/this->board.squareSize] = 'K';
                        else boardCopy.controlBoard[validSquare.y/this->board.squareSize][validSquare.x/this->board.squareSize] = 'k';

                        piece->showMoveOptions(boardCopy);

                        for(SDL_Rect validSquare2 : piece->getValidSquares()){
                            if(validSquare.x == validSquare2.x && validSquare.y == validSquare2.y){

                               king->enemyPiecesValidSquares.push_back(validSquare2);
                                cout << "check" << endl;

                            }
                        }

                        piece->resetValidSquares();
                        boardCopy = this->board;
                    }

                }


            }

            king->resetValidSquares();
            king->showMoveOptions(this->board);
            king->enemyPiecesValidSquares.clear();

        }else{

            cout << "mexendo outra peca" << endl;
            King * friendKing = nullptr;
            for(King* k : this->kings){
                if(!this->getSelectedPiece()->isAEnemyPiece(k->getCoordinate(), this->board) ){
                       friendKing = k;
                }
            }


            Board boardCopy = this->board;
            boardCopy.controlBoard[this->getSelectedPiece()->getCoordinate().y][this->getSelectedPiece()->getCoordinate().x] = '0';

            //2)pegas todas as posicoes validas das peças inimigas da peça selecionada
            for(Piece* piece : this->pieces){
                if(this->getSelectedPiece()->isAEnemyPiece(piece->getCoordinate(), this->board)){

                    piece->showMoveOptions(boardCopy);

                        for(SDL_Rect validSquare : piece->getValidSquares()){
                            if(friendKing)
                                friendKing->enemyPiecesValidSquares.push_back(validSquare);
                        }


                     piece->resetValidSquares();
                }
            }

            if(!friendKing){
                this->getSelectedPiece()->showMoveOptions(this->board);
                return;
            }

            if(!friendKing->isOnCheck(friendKing->getCoordinate(), boardCopy)){
                 this->getSelectedPiece()->showMoveOptions(this->board);
            }else{
                cout << "o rei ta em check mano" << endl;
            }

            friendKing->enemyPiecesValidSquares.clear();

        }



};



void Game::renderPieces(){
    for(Piece* piece : this->pieces){
        if(this->getSelectedPiece() == piece) continue;
        SDL_RenderCopy(this->getRenderer(), this->piecesTextures, piece->getOrigin(), piece->getDestiny());
    }

    //Sempre renderiza a peça selecionada por último para ela ficar por cima de todas
    if(this->getSelectedPiece()){
        SDL_RenderCopy(this->getRenderer(), this->piecesTextures, this->getSelectedPiece()->getOrigin(), this->getSelectedPiece()->getDestiny());
    }
};

void Game::checkCapture(){

    int index = 0;
    for(Piece* piece : this->pieces){
          SDL_Point coordinate = piece->getCoordinate();
          if(this->getSelectedPiece() != piece){
              if(this->getSelectedPiece()->getCoordinate().x == coordinate.x &&
                  this->getSelectedPiece()->getCoordinate().y == coordinate.y){

                  delete piece;
                  this->pieces.erase(this->pieces.begin() + index);
                  break;
              }
          }

          index++;
    }
};



void Game::end(){
    for(Piece* piece : this->pieces){
        delete piece;
    }
    SDL_DestroyTexture(this->getBoard()->getTexture());
    SDL_DestroyTexture(this->piecesTextures);
    SDL_DestroyRenderer(this->getRenderer());
    SDL_DestroyWindow(this->getWindow());
    SDL_Quit();
};
