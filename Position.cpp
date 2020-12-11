#include "Position.hpp"

Position::Position(){
}
Position::Position(Piece my_piece, int x_, int y_) : piece(my_piece), x(x_), y(y_){
}

Piece Position::getPiece(){
    return piece;
}
void Position::setPiece(Piece c){
    piece=c;
}
int Position::getx(){
    return x;
}
int Position::gety(){
    return y;
}
void Position::setx(int x_){
    x=x_;
}
void Position::sety(int y_){
    y=y_;
}