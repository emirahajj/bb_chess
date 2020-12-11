#ifndef PIECE_
#define PIECE_

//A piece is either white or black or "empty"

#include <string>

namespace piece_details
{
    enum piece_type
    {
        BLACK = 0,
        WHITE = 1,
        EMPTY = 2
    };
}

class Piece
{
private:
    //true is black, false is white
    piece_details::piece_type p_type;

public:
    Piece();
    Piece(int kind_of_piece);
    void setStatus(int kind_of_piece);
    std::string getStatus();
};

#endif
