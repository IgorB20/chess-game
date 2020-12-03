#include <QCoreApplication>
#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Board.h>
#include <vector>
#include <Pawn.h>

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        cout << SDL_GetError() << endl;


    SDL_Window* window = SDL_CreateWindow("Chess",
                                             SDL_WINDOWPOS_CENTERED,
                                             SDL_WINDOWPOS_CENTERED,
                                             500, 500,
                                             0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    bool running = true;

    Board board;
    board.destiny = {.x= 0, .y= 0, .w= 1000/2, .h= 1000/2};
    board.texture = IMG_LoadTexture(renderer,"assets/images/board.png");

    SDL_Texture* pecas = IMG_LoadTexture(renderer, "assets/images/pieces.png");

    //TESTESS
    Pawn peao = {"white"};

    vector<Piece*> whitePieces;
    whitePieces.push_back(&peao);


    peao.setDestiny({.x=0, .y=64, .w=50, .h=50});

    SDL_Point positionBackup = {.x=0,
                               .y=64};

    const int squareSize = 124/2;
    SDL_Rect validSquare = {.x = 0, .y = 0, .w=squareSize, .h=squareSize};

    //tile size 124px

    bool leftMouseButtonDown = false;
    SDL_Point mousePos;
    SDL_Point clickOffset;
    Piece* selectedPiece = nullptr;

    /////////////

    SDL_Event event;

    while(running)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,  board.texture, NULL, &board.destiny);

        for(Piece* piece : whitePieces){
            if(selectedPiece == piece) continue;
            SDL_RenderCopy(renderer, pecas, piece->getOrigin(), piece->getDestiny());
        }
        //Sempre renderiza a peça selecionada por último para ela ficar por cima de todas
        if(selectedPiece){
            SDL_RenderCopy(renderer, pecas, selectedPiece->getOrigin(), selectedPiece->getDestiny());
        }



        SDL_RenderPresent(renderer);

          while (SDL_PollEvent(&event)){
              switch(event.type){
                  case SDL_QUIT:
                      running = false;
                      break;

                  case SDL_MOUSEMOTION:
                      mousePos = { event.motion.x, event.motion.y };
                      if (leftMouseButtonDown && selectedPiece){
                          if(SDL_PointInRect(&mousePos, &validSquare)){
                              cout << "em cima" << endl;
                          }else{
                              cout << "nao" << endl;
                          }
                          selectedPiece->getDestiny()->x = mousePos.x - clickOffset.x;
                          selectedPiece->getDestiny()->y = mousePos.y - clickOffset.y;
                       }
                      break;

                  case SDL_MOUSEBUTTONDOWN:
                   if (!leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT){

                       leftMouseButtonDown = true;

                       for(Piece* piece : whitePieces){
                           if(SDL_PointInRect(&mousePos, piece->getDestiny())){
                               selectedPiece = piece;
                               clickOffset.x = mousePos.x - piece->getDestiny()->x;
                               clickOffset.y = mousePos.y - piece->getDestiny()->y;
                           }
                       }

                   }
                      break;

                   case SDL_MOUSEBUTTONUP:
                          if(SDL_PointInRect(&mousePos, &validSquare)){
                              selectedPiece->getDestiny()->x = validSquare.x;
                              selectedPiece->getDestiny()->y = validSquare.y;
                          }else{
                              selectedPiece->getDestiny()->x = positionBackup.x;
                              selectedPiece->getDestiny()->y = positionBackup.y;
                          }
                        leftMouseButtonDown = false;
                        selectedPiece = nullptr;


              }



          }

        SDL_Delay(1000/60);
    }

    SDL_DestroyTexture(board.texture);
    SDL_FreeSurface(board.surface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return a.exec();
}
