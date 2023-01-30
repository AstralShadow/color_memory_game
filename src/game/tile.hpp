#ifndef INCLUDE_TILE_HPP
#define INCLUDE_TILE_HPP

#include "utils/types.hpp"

namespace game
{
    struct Tile
    {
        int color = -1;
        bool visible = false;
        int shown_time = 0;
    };
}

#endif // INCLUDE_TILE_HPP
