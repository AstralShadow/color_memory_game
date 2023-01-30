#include "game/game.hpp"
#include "core/core.hpp"
#include "game/board.hpp"
#include "utils/point.hpp"
#include <SDL2/SDL_events.h>


void game::keydown(SDL_KeyboardEvent& ev, scene_uid)
{
    auto& scancode = ev.keysym.scancode;
    if(scancode == SDL_SCANCODE_Q)
        core::stop();
}


static bool has_open = false;
static Point open {0, 0};

void game::mousedown(SDL_MouseButtonEvent& ev, scene_uid)
{
    Point size {
        800 / board.width,
        600 / board.height
    };

    int x = ev.x / size.x;
    int y = ev.y / size.y;

    if(!has_open) {
        auto* tile = board.at(x, y);
        if(!tile->visible) {
            tile->visible = true;
            has_open = true;
            open = {x, y};
        }
    } else {
        auto* other = board.at(open.x,
                               open.y);
        auto* current = board.at(x, y);

        if(other == current) {
            current->visible = false;
            has_open = false;
            return;
        }

        if(current->visible)
            return;

        has_open = false;

        if(current->color != other->color) {
            other->visible = false;
            current->visible = false;
            other->shown_time = 500;
            current->shown_time = 500;
        } else current->visible = true;
    }
}

