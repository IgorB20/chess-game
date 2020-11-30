#include <QCoreApplication>
#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Board.h>

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
    board.surface = IMG_Load("assets/images/board.png");
    board.destiny = {.x= 0, .y= 0, .w= 1000/2, .h= 1000/2};
    cout << SDL_GetError() << endl;
    board.texture = SDL_CreateTextureFromSurface(renderer, board.surface);

    while(running)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,  board.texture, NULL, &board.destiny);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(board.texture);
    SDL_FreeSurface(board.surface);

    return a.exec();
}
