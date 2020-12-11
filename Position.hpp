#ifndef POSITION_
#define POSITION_

//Position contains a piece and a coordinate.

#include "Piece.hpp"

class Position
{
private:
    Piece piece;
    int x;
    int y;
public:
    Position();
    Position(Piece my_piece, int x_, int y_);
    Piece getPiece();
    void setPiece(Piece c);
    int getx();
    int gety();
    void setx(int x_);
    void sety(int y_);
};

#endif