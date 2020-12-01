#include <QCoreApplication>
#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Board.h>

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
    cout << SDL_GetError() << endl;

    Pawn peao = {"white"};
    peao.setDestiny({.x=250, .y=250, .w=50, .h=50});

    SDL_Rect teste = peao.getOrigin();
    SDL_Rect teste2 = peao.getDestiny();

    SDL_Event event;
    while(running)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,  board.texture, NULL, &board.destiny);
        SDL_RenderCopy(renderer, pecas, &teste, &teste2);
        SDL_RenderPresent(renderer);

          while (SDL_PollEvent(&event)){
              if(event.type == SDL_QUIT) running = false;
          }
    }

    SDL_DestroyTexture(board.texture);
    SDL_FreeSurface(board.surface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return a.exec();
}
