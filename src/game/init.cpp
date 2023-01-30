#include "game/game.hpp"
#include "game/board.hpp"

namespace game
{
    Board board(5, 4);
}


void game::init(int, char**, scene_uid)
{
    board.generate_tiles();
}

void game::deinit(scene_uid)
{

}
