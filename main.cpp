#include <iostream>
#include "Game.hpp"
#include <stdio.h>
#include "colors.hpp"


using namespace std;
 
int main(){

    //create a Game (i.e a board)
    Game a; 
    a.setGame();
    //a.drawBoard();

    int i, j, newi, newj, v;

    //this is a comment

    // cout<<a.canWhiteAdvance(a.getPieceAtPos(7,5))<<endl;
    // cout<<a.canWhiteAdvance(a.getPieceAtPos(6,5))<<endl;
    while (!a.getGameOver())
    {   
        a.drawBoard();
        //display that tells which users turn it is
        a.whoseTurn();
        //prompt to enter coords
        cout<<"Enter the coordinates \nof your piece and it's \nnew position (e.g. 6 0 5 0): \n";

        //are you moving to a valid space? is it on the board? is it allowed (within your piece move limits)
        cin>>j>>i>>newj>>newi;
        
        // if user tried to move a piece that isn't theirs, tries to "move" and empty spot, 
        //or picks a spot not on the board
        while(!a.isThisYourPiece(a.getPieceAtPos(i,j)) || !a.isValidCoord(i, j)){
            cout<<"Please choose a piece that belongs to you: ";
            cin>>j>>i>>newj>>newi;
        }
        //top right 4 white works
       
        while (!a.isValidMove(a.getPieceAtPos(i,j), newi, newj)){
            cout<<"That's not a valid move! Try again. ";
            cin>>j>>i>>newj>>newi;
        }
        

        //move the piece
        a.move(a.getPieceAtPos(i,j), newi, newj);
        //draw the board after move
        //before next iteration, we switch the player turn state to ensure that people are moving their own pieces etc.
        a.switchTurn();
        //setGameOver runs and sets the game to be over if either pieces make it to the other end
        a.setGameOver();
    }
    a.printWinner();
}