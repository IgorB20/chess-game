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

        if((!game.isWhiteTurn && !game.bot.isWhite) || (game.isWhiteTurn && game.bot.isWhite)){
            cout << "hm" << endl;

            game.bot.choosePiece(game.getBoard(), game.pieces);
            SDL_Point oldCoordinate = game.bot.selectedPiece->getCoordinate();
            game.bot.chooseMove(game.getBoard());

            game.registerPlay(game.bot.selectedPiece);

            game.getBoard()->update(oldCoordinate, game.bot.selectedPiece->getCoordinate());

            game.updateTurn();
            game.bot.selectedPiece = nullptr;

            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    cout << game.getBoard()->controlBoard[i][j] << " ";
                }
                cout << endl;

            }
               cout << endl;
        }

          while (SDL_PollEvent(&event)){


              switch(event.type){
                  case SDL_QUIT:
                     game.setRunning(false);
                      break;

                  case SDL_MOUSEMOTION:
                      mousePos = { event.motion.x, event.motion.y };
                      if (leftMouseButtonDown && game.getSelectedPiece()){
                          game.getSelectedPiece()->updatePosition({.x=mousePos.x - clickOffset.x, .y=mousePos.y - clickOffset.y});
                          //game.getSelectedPiece()->getDestiny()->x = mousePos.x - clickOffset.x;
                          //game.getSelectedPiece()->getDestiny()->y = mousePos.y - clickOffset.y;
                       }
                      break;

                  case SDL_MOUSEBUTTONDOWN:
                   if (!leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT){

                       leftMouseButtonDown = true;

                       for(Piece* piece : game.pieces){
                           if((piece->isWhite() && !game.isWhiteTurn) || (!piece->isWhite() && game.isWhiteTurn)) continue;

                           if(SDL_PointInRect(&mousePos, piece->getDestiny())){
                               game.setSelectedPiece(piece);
                               game.checkChecks();
                               clickOffset.x = mousePos.x - piece->getDestiny()->x;
                               clickOffset.y = mousePos.y - piece->getDestiny()->y;
                           }
                       }

                   }
                      break;

                   case SDL_MOUSEBUTTONUP:
                    if(game.getSelectedPiece()){

                        if(game.getSelectedPiece()->getValidSquares().size() == 0){
                            game.getSelectedPiece()->restorePosition(game.getBoard()->squareSize);

                        }

                        if(!game.castle(mousePos)){
                            for(SDL_Rect validSquare : game.getSelectedPiece()->getValidSquares()){

                                if(SDL_PointInRect(&mousePos, &validSquare)){

                                    if(game.getSelectedPiece()->isFirstMove) game.getSelectedPiece()->isFirstMove = false;

                                    game.getSelectedPiece()->updatePosition(validSquare);

                                     SDL_Point oldCoordinate = game.getSelectedPiece()->getCoordinate();

                                     game.getSelectedPiece()->setCoordinate({.x =validSquare.x/game.getBoard()->squareSize,
                                                                            .y=validSquare.y/game.getBoard()->squareSize
                                                                          });


                                     game.getBoard()->update(oldCoordinate, game.getSelectedPiece()->getCoordinate());

                                     game.getSelectedPiece()->resetValidSquares();

                                     game.registerPlay(game.getSelectedPiece());
                                     //game.checkMate();

                                     game.updateTurn();

                                     //BOT

                                     break;

                                }else{

                                    game.getSelectedPiece()->restorePosition(game.getBoard()->squareSize);
                                }
                            }
                        }



                    }

                    leftMouseButtonDown = false;
                    game.setSelectedPiece(nullptr);


                    for(int i = 0; i < 8; i++){
                        for(int j = 0; j < 8; j++){
                            cout << game.getBoard()->controlBoard[i][j] << " ";
                        }
                        cout << endl;

                    }
                       cout << endl;

              }
          }

        SDL_Delay(1000/60);
    }

    game.end();



    return a.exec();
}
