
#ifndef GAME_
#define GAME_

#include "Position.hpp"


class Game
{
private:
    //2d array of Positions to represent board
    Position board[8][8];
    //keeps track of current players turn
    bool isWhitesTurn;
    //keeps track of whether or not the game is over
    bool gameOver;
    //score private members
    int blackScore;
    int whiteScore;


public:
    Game();
    //set up initial board
    void setGame();

    //draws the current state of the board
    void drawBoard();

    //returns the Position object at that coordinate
    Position getPieceAtPos(int i, int j);

    //move function that moves the pieces across the board
    void move(Position pos, int i, int j);

    //bool that checks to see if the input is a valid board coordinate
    bool isValidCoord(int i, int j);

    //bool that checks to see if the piece you're picking is your piece
    bool isThisYourPiece(Position pos);
    
    //bool that returns true if there is an empty space to move to above/below pawns
    bool canAdvance(Position pos);

    //returns whether or not the game has ended
    bool getGameOver();

    //sets the game status to over if someone's piece is at the opposite end of the board
    void setGameOver();

    //Prints the current players turn.
    void whoseTurn();

    //toggles the turn to the other player
    void switchTurn();
    
    //checks if move is an overtaking move
    bool isValidMove(Position pos, int i, int j);

    //prints the winner in the terminal window
    void printWinner();

};

#endif 


