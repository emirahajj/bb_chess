
#include <iostream>
#include <iomanip>
#include "Game.hpp"
#include "colors.hpp"


using namespace std;
 

Game::Game(): isWhitesTurn(true), blackScore(0), whiteScore(0), gameOver(false)
{
    setGame();
}

Position Game::getPieceAtPos(int i, int j){
    return board[i][j];
}
void Game::setGame()
{
    //setting up the initial board
    for (int i = 0; i < 8; i++){
        for (int j = 0; j< 8; j++){
            //the black pieces
            if (i==1){
                board[i][j]=Position(0, i, j);
            }
            //the white pieces
            else if (i==6){
                board[i][j]=Position(1, i, j);
            }
            //the empty spots
            else{
                board[i][j]= Position(2, i, j);
            }
        }
    }
}
//drawing the board onto the table
void Game::drawBoard(){
    
    cout << " ";
    for (int i = 0; i < 8; i++)
    {
        //cout<<setw(3);
        cout<<" "<<i<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 8; i++){
        cout<<i;
        for (int j = 0; j< 8; j++){
            //the black pieces
            cout<<setw(3);
            if (board[i][j].getPiece().getStatus()=="BLACK"){
                cout << SetBackBLK << SetForeWHT <<setw(2)<<" B "<<RESETTEXT; 
            }
            else if (board[i][j].getPiece().getStatus()=="WHITE"){
                //cout <<setw(2);
                cout << SetBackWHT << SetForeBLK <<setw(2)<<" W "<<RESETTEXT;
            } else{
                cout<<" . ";
            }                
        }
        cout<<endl;
    }

}

//returns whether that coordinate is valid or not
bool Game::isValidCoord(int i, int j){
    return ((i<8 && i>=0) && (j<8 && j>=0));
}
bool Game::isThisYourPiece(Position pos){
    string stat = pos.getPiece().getStatus();

    if ((stat=="WHITE" && isWhitesTurn == false) || (stat=="BLACK" && isWhitesTurn == true) || (stat=="EMPTY")){
        return false;
    }
    return true;
}

//checks if the spot in front of it is empty
bool Game::canAdvance(Position pos){
    int xcoord = pos.getx();
    int ycoord = pos.gety();
    std::string status = pos.getPiece().getStatus();
    
    if (status == "WHITE" && board[xcoord-1][ycoord].getPiece().getStatus()=="EMPTY"){
        return true;
    }
    else if(status == "BLACK" && board[xcoord+1][ycoord].getPiece().getStatus()=="EMPTY"){
        return true;
    }
    return false;
}


void Game::move(Position pos, int i, int j){
    int xcoord = pos.getx();
    int ycoord = pos.gety();
    string type = pos.getPiece().getStatus();

    if (pos.getPiece().getStatus()=="WHITE"){
        
        //empty spot where white can move to
        if (canAdvance(pos) && (xcoord ==i+1 && ycoord ==j)){
            board[xcoord-1][ycoord].setPiece(1);
        }
        //spot in topleft where you can move to
        if (isValidMove(pos, i, j) && (board[xcoord-1][ycoord-1].getPiece().getStatus()=="BLACK")){
            board[xcoord-1][ycoord-1].setPiece(1);
        }
        //spot in topright where you can move to
        if (isValidMove(pos, i, j) && board[xcoord-1][ycoord+1].getPiece().getStatus()=="BLACK"){
            board[xcoord-1][ycoord+1].setPiece(1);
        }
    } else if (pos.getPiece().getStatus()=="BLACK"){
        if (canAdvance(pos) && (xcoord ==i-1 && ycoord ==j)){
            board[xcoord+1][ycoord].setPiece(0);
        }
        //bottomleft
        if (isValidMove(pos, i, j) && (board[xcoord+1][ycoord-1].getPiece().getStatus()=="WHITE")){
            board[xcoord+1][ycoord-1].setPiece(0);
        }
        //bottomright
        if (isValidMove(pos, i, j) && board[xcoord+1][ycoord+1].getPiece().getStatus()=="WHITE"){
            board[xcoord+1][ycoord+1].setPiece(0);
        }
    }
    board[xcoord][ycoord].setPiece(2);
}

bool Game::getGameOver(){
    return gameOver;
}

void Game::whoseTurn(){
    string turn; 
    turn = isWhitesTurn ? "WHITE'S TURN" : "BLACK'S TURN";
    cout<<endl<<turn<<endl;
}

void Game::switchTurn(){
    isWhitesTurn = !isWhitesTurn;
}

bool Game::isValidMove(Position pos, int i, int j){
    int xcoord = pos.getx();
    int ycoord = pos.gety();
    string below = board[xcoord+1][ycoord].getPiece().getStatus();
    string above = board[xcoord-1][ycoord].getPiece().getStatus();
    string topleft = board[xcoord-1][ycoord-1].getPiece().getStatus();
    string topright = board[xcoord-1][ycoord+1].getPiece().getStatus();
    string bottomleft = board[xcoord+1][ycoord-1].getPiece().getStatus();
    string bottomright = board[xcoord+1][ycoord+1].getPiece().getStatus();

    string type = pos.getPiece().getStatus();
    //if black, true if space below it is empty, OR if space to bottom left or right is WHITE
    if (type == "BLACK" && ((below == "EMPTY" && (i ==xcoord+1 && ycoord ==j)) || (bottomleft == "WHITE" && (i ==xcoord+1 && j ==ycoord-1)) || (bottomright == "WHITE" && (i ==xcoord+1 && j ==ycoord+1))))
    {
        return true;
    }
    if (type == "WHITE" && ((above == "EMPTY" && (i ==xcoord-1 && ycoord ==j)) || (topleft == "BLACK" && (i ==xcoord-1 && j ==ycoord-1)) || (topright == "BLACK" && (i ==xcoord-1 && j ==ycoord+1))))
    {
        return true;
    }
    return false;
    //if white, true if space above it is empty, OR if spave to top left of right is WHITE
}

void Game::printWinner(){
    cout<<(isWhitesTurn ? "BLACK WON!": "WHITE WON!")<<endl;
}

void Game::setGameOver(){
    for (int i = 0; i<8; i++){
        if (getPieceAtPos(0,i).getPiece().getStatus() == "WHITE" || getPieceAtPos(7,i).getPiece().getStatus() == "BLACK")
        {
           gameOver=true;
        }
    }
}

