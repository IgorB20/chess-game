#include <Game.h>
#include <Pawn.h>
#include <Knight.h>
#include <iostream>

#include <PiecesInitializer.h>

#include <King.h>

Game::Game(){
    this->init();
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

    //inicializando reis - COLOCAR ISSO NUMA FUNÇÃO
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

bool Game::castle( SDL_Point mousePos){
    King * king = nullptr;
    for(King* k : this->kings){
        if(this->getSelectedPiece() == k){
               king = k;
        }
    }

        if(king){
            if(king->isCastlePossible && king->castleRook){

                if(SDL_PointInRect(&mousePos, &king->castleSquare)){
                    cout << "fazendo o rock" << endl;

                     //ATUALIZANDO COORDENADA DO REI
                    king->updatePosition({.x=(king->getCoordinate().x+(2*king->castleDirection))*board.squareSize,
                                          .y=king->getDestiny()->y});
                    SDL_Point oldCoordinate = king->getCoordinate();
                    king->setCoordinate({.x =king->castleSquare.x/this->getBoard()->squareSize,
                                                           .y=king->castleSquare.y/this->getBoard()->squareSize
                                                         });
                    this->getBoard()->update(oldCoordinate, king->getCoordinate());

                    //ATUALIZANDO COORDENADA Da TORRE
                   king->castleRook->updatePosition({.x=(king->getCoordinate().x-(1*king->castleDirection))*board.squareSize,
                                         .y=king->castleRook->getDestiny()->y});
                   SDL_Point oldCoordinate2 = king->castleRook->getCoordinate();
                   king->castleRook->setCoordinate({.x =king->getCoordinate().x-(1*king->castleDirection),
                                                          .y=king->castleRook->getCoordinate().y
                                                        });
                   this->getBoard()->update(oldCoordinate2, king->castleRook->getCoordinate());

                    king->isCastlePossible = false;
                    king->castleRook->isFirstMove = false;
                    king->castleRook = nullptr;
                    king->castleSquare = {};
                    king->isFirstMove = false;
                    return true;
                }
            }

            //grande roque
            if(king->isBigCastlePossible && king->bigCastleRook){

                if(SDL_PointInRect(&mousePos, &king->bigCastleSquare)){
                    cout << "fazendo o grand roque" << endl;

                     //ATUALIZANDO COORDENADA DO REI
                    king->updatePosition({.x=(king->getCoordinate().x+((2*king->castleDirection)*-1))*board.squareSize,
                                          .y=king->getDestiny()->y});
                    SDL_Point oldCoordinate = king->getCoordinate();
                    king->setCoordinate({.x =king->bigCastleSquare.x/this->getBoard()->squareSize,
                                                           .y=king->bigCastleSquare.y/this->getBoard()->squareSize
                                                         });
                    this->getBoard()->update(oldCoordinate, king->getCoordinate());

                    //ATUALIZANDO COORDENADA Da TORRE
                   king->bigCastleRook->updatePosition({.x=(king->getCoordinate().x-((1*king->castleDirection)*-1))*board.squareSize,
                                         .y=king->bigCastleRook->getDestiny()->y});
                   SDL_Point oldCoordinate2 = king->bigCastleRook->getCoordinate();
                   king->bigCastleRook->setCoordinate({.x =king->getCoordinate().x-((1*king->castleDirection)*-1),
                                                          .y=king->bigCastleRook->getCoordinate().y
                                                        });
                   this->getBoard()->update(oldCoordinate2, king->bigCastleRook->getCoordinate());

                    king->isBigCastlePossible = false;
                    king->bigCastleRook->isFirstMove = false;
                    king->bigCastleRook = nullptr;
                    king->bigCastleSquare = {};
                    king->isFirstMove = false;
                    return true;
                }
            }
        }

        return false;
};

void Game::checkChecks(){

    King * king = nullptr;
    for(King* k : this->kings){
        if(this->getSelectedPiece() == k){
               king = k;
        }
    }

        if(king){


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
                            //if(validSquare.x == validSquare2.x && validSquare.y == validSquare2.y){

                               king->enemyPiecesValidSquares.push_back(validSquare2);
                                //cout << "check" << endl;

                            //}
                        }

                        piece->resetValidSquares();
                        boardCopy = this->board;
                    }

                }


            }





            king->resetValidSquares();
            king->showMoveOptions(this->board);
            king->checkCastle(this->pieces, this->board);
            king->checkBigCastle(this->pieces, this->board);
            //cout << king->isOnCheck(king->getCoordinate(), this->board) << endl;
            king->enemyPiecesValidSquares.clear();

        }else{

            cout << "mexendo outra peca" << endl;
            King * friendKing = nullptr;
            for(King* k : this->kings){
                if(!this->getSelectedPiece()->isAEnemyPiece(k->getCoordinate(), this->board) ){
                       friendKing = k;
                }
            }

            if(!friendKing){
                this->getSelectedPiece()->showMoveOptions(this->board);
                return;
            }


            Board boardCopy = this->board;

            vector<SDL_Rect> newSquares = {};
            vector<SDL_Rect> kingBackup;
            int squareSize = this->board.squareSize;
            char pieceIdentifier = boardCopy.controlBoard[this->getSelectedPiece()->getCoordinate().y][this->getSelectedPiece()->getCoordinate().x];
            boardCopy.controlBoard[this->getSelectedPiece()->getCoordinate().y][this->getSelectedPiece()->getCoordinate().x] = '0';
            Board boardCopy2 = boardCopy;

            this->getSelectedPiece()->showMoveOptions(this->board);

            for(SDL_Rect validSquare : this->selectedPiece->getValidSquares()){
                boardCopy2.controlBoard[validSquare.y/squareSize][validSquare.x/squareSize] = pieceIdentifier;

                for(Piece* piece : this->pieces){
                    if(this->getSelectedPiece()->isAEnemyPiece(piece->getCoordinate(), this->board)){

                        if(piece->getCoordinate().x*squareSize == validSquare.x && piece->getCoordinate().y*squareSize == validSquare.y) continue;


                            piece->showMoveOptions(boardCopy2);

                                for(SDL_Rect validSquare2 : piece->getValidSquares()){
                                    if(friendKing){
                                        kingBackup.push_back(validSquare2);
                                        friendKing->enemyPiecesValidSquares.push_back(validSquare2);
                                    }

                                }


                             piece->resetValidSquares();


                    }
                }

                if(!friendKing->isOnCheck(friendKing->getCoordinate(), this->board)){
                    newSquares.push_back(validSquare);
                }
                friendKing->enemyPiecesValidSquares.clear();
                boardCopy2 = boardCopy;
            }



            friendKing->enemyPiecesValidSquares = kingBackup;
            if(friendKing->isOnCheck(friendKing->getCoordinate(), this->board)){
                this->getSelectedPiece()->resetValidSquares();
                cout << "o rei ta xeque" << endl;
                cout << newSquares.size() << endl;
                this->selectedPiece->setValidSquares(newSquares);
                newSquares.clear();
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
