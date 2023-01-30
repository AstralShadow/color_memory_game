#include "game/game.hpp"
#include "core/core.hpp"
#include "game/board.hpp"
#include "game/colors.hpp"
#include <SDL2/SDL_render.h>

static auto& rnd = core::renderer;

void game::render(scene_uid)
{
    SDL_RenderClear(rnd);

    SDL_Rect area {
        0, 0,
        800 / board.width,
        600 / board.height
    };

    for(int y = 0; y < board.height; ++y)
    for(int x = 0; x < board.width; ++x) {
        area.x = area.w * x;
        area.y = area.h * y;
        Tile* tile = board.at(x, y);
        auto c = colors[tile->color];

        bool visible = tile->visible
            || tile->shown_time > 0;
        if(visible)
            SDL_SetRenderDrawColor
                (rnd, c.r, c.g, c.b, c.a);
        else
            SDL_SetRenderDrawColor
                (rnd, 0, 0, 0, 255);

        SDL_RenderFillRect(rnd, &area);

        if(visible)
            SDL_SetRenderDrawColor
                (rnd, 0, 0, 0, 255);
        else
            SDL_SetRenderDrawColor
                (rnd, 255, 255, 255, 255);

        SDL_RenderDrawRect(rnd, &area);
    }

    SDL_RenderPresent(rnd);
}
