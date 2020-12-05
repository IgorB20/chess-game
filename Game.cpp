#include <Game.h>
#include <Pawn.h>
#include <Knight.h>
#include <iostream>

#include <PiecesInitializer.h>

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

Board Game::getBoard(){
    return this->board;
};

void Game::renderBoard(){
 SDL_RenderCopy(this->getRenderer(),  this->getBoard().getTexture(), NULL, this->getBoard().getDestiny());
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



void Game::end(){
    for(Piece* piece : this->pieces){
        delete piece;
    }
    SDL_DestroyTexture(this->getBoard().getTexture());
    SDL_DestroyTexture(this->piecesTextures);
    SDL_DestroyRenderer(this->getRenderer());
    SDL_DestroyWindow(this->getWindow());
    SDL_Quit();
};
