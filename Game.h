#ifndef GAME_H
#define GAME_H


#include <SDL2/SDL.h>
#include <Board.h>
#include <Piece.h>
#include <vector>
#include <Bot.h>

#include <King.h>

class Game{
    public:

        vector<Piece*> pieces; //deixar publico por enquanto
        bool running;
        bool isWhiteTurn;
        Bot bot;
        bool playerIsWhite;

        vector<King*> kings;
        void checkChecks();

        Game();
        void sortColors();
        void updateTurn();
        void registerPlay(Piece* piece);
        bool checkMate();
        void renderBoard();
        void renderPieces();
        void setRunning(bool running);
        void end();
        bool isRunning();
        bool checkCapture(Piece* piece);
        bool castle(SDL_Point mousePos);
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
