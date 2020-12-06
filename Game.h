#ifndef GAME_H
#define GAME_H


#include <SDL2/SDL.h>
#include <Board.h>
#include <Piece.h>
#include <vector>

class Game{
    public:

        vector<Piece*> pieces; //deixar publico por enquanto
        bool running;

        Game();
        void renderBoard();
        void renderPieces();
        void setRunning(bool running);
        void end();
        bool isRunning();
        void checkCapture();
        void setSelectedPiece(Piece* piece);
        Piece* getSelectedPiece();
        SDL_Renderer* getRenderer();
        SDL_Window* getWindow();
        Board* getBoard();


    private:
        SDL_Texture* piecesTextures = nullptr;
        Piece* selectedPiece = nullptr;
        SDL_Window* window = nullptr;
        SDL_Renderer * renderer = nullptr;
        Board board = NULL;

        void initWindow();
        void init();
};

#endif // GAME_H
