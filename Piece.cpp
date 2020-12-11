#include <string>
#include "Piece.hpp"


Piece::Piece(){
}

Piece::Piece(int kind_of_piece){
    p_type = static_cast<piece_details::piece_type>(kind_of_piece);
}

void Piece::setStatus(int kind_of_piece){
    p_type = static_cast<piece_details::piece_type>(kind_of_piece);
}

std::string Piece::getStatus(){
    switch (p_type)
    {
        case piece_details::BLACK:
            return "BLACK";
        case piece_details::WHITE:
            return "WHITE";
        case piece_details::EMPTY:
            return "EMPTY";
        default:
            return "";
    }
}

