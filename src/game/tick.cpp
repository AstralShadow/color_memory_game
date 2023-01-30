#include "game/game.hpp"
#include "game/board.hpp"

void game::tick(u32 ms, scene_uid)
{
    for(int y = 0; y < board.height; ++y)
    for(int x = 0; x < board.width; ++x) {
        Tile* tile = board.at(x, y);
        tile->shown_time -= ms;
        if(tile->shown_time < 0)
            tile->shown_time = 0;
    }
}
