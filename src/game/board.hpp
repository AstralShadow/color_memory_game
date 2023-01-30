#ifndef INCLUDE_BOARD_HPP
#define INCLUDE_BOARD_HPP

#include "utils/types.hpp"
#include "game/tile.hpp"

namespace game
{
    class Board
    {
    public:
        Board(u8 w, u8 h);
        ~Board();

        const int width;
        const int height;

        Tile* at(int x, int y);

        void generate_tiles();

    private:
        Tile* data;
    };

    extern Board board;
}

#endif // INCLUDE_BOARD_HPP
