#include <QCoreApplication>
#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Board.h>
#include <Game.h>
#include <vector>
#include <Pawn.h>

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Game game;

    //TESTESS
    //Pawn peao = {"white", {.x=0, .y=124}};
    //peao.setDestiny({.x=0, .y=64, .w=50, .h=50});

    //game.pieces.push_back(&peao);

    SDL_Rect validSquare = {.x = 0, .y = 0, .w= game.getBoard().squareSize, .h= game.getBoard().squareSize};

    //criar struct de mouse
    bool leftMouseButtonDown = false;
    SDL_Point mousePos;
    SDL_Point clickOffset;


    ///////////

    SDL_Event event;

    while(game.isRunning())
    {
        SDL_RenderClear(game.getRenderer());
        game.renderBoard();
        game.renderPieces();
        SDL_RenderPresent(game.getRenderer());

          while (SDL_PollEvent(&event)){
              switch(event.type){
                  case SDL_QUIT:
                     game.setRunning(false);
                      break;

                  case SDL_MOUSEMOTION:
                      mousePos = { event.motion.x, event.motion.y };
                      if (leftMouseButtonDown && game.getSelectedPiece()){
                          if(SDL_PointInRect(&mousePos, &validSquare)){
                              cout << "em cima" << endl;
                          }else{
                              cout << "nao" << endl;
                          }
                          game.getSelectedPiece()->getDestiny()->x = mousePos.x - clickOffset.x;
                          game.getSelectedPiece()->getDestiny()->y = mousePos.y - clickOffset.y;
                       }
                      break;

                  case SDL_MOUSEBUTTONDOWN:
                   if (!leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT){

                       leftMouseButtonDown = true;

                       for(Piece* piece : game.pieces){
                           if(SDL_PointInRect(&mousePos, piece->getDestiny())){
                               game.setSelectedPiece(piece);
                               clickOffset.x = mousePos.x - piece->getDestiny()->x;
                               clickOffset.y = mousePos.y - piece->getDestiny()->y;
                           }
                       }

                   }
                      break;

                   case SDL_MOUSEBUTTONUP:
                          if(SDL_PointInRect(&mousePos, &validSquare)){
                              game.getSelectedPiece()->getDestiny()->x = validSquare.x;
                              game.getSelectedPiece()->getDestiny()->y = validSquare.y;
                          }else{
                              game.getSelectedPiece()->getDestiny()->x = game.getSelectedPiece()->getCoordinate()->x;
                              game.getSelectedPiece()->getDestiny()->y = game.getSelectedPiece()->getCoordinate()->y;
                          }
                        leftMouseButtonDown = false;
                        game.setSelectedPiece(nullptr);


              }



          }

        SDL_Delay(1000/60);
    }

    game.end();



    return a.exec();
}
