#include "game/board.hpp"
#include <stdexcept>

using game::Board;
using game::Tile;


Board::Board(u8 w, u8 h) :
    width(w), height(h)
{
    data = new Tile[w * h];
    if(w * h % 2)
        throw new std::runtime_error
            ("Odd number of tiles!");
}

Board::~Board()
{
    delete[] data;
}


Tile* Board::at(int x, int y)
{
    int pos = y * width + x;
    int size = width * height;
    if(pos < 0 || pos >= size)
        return nullptr;
    return data + pos;
}
