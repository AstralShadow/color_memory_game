#ifndef INCLUDE_COLORS_HPP
#define INCLUDE_COLORS_HPP

#include <SDL2/SDL_pixels.h>

namespace game
{
    const int colors_count = 8;
    const SDL_Color colors[]
    {
        {255,   0,   0, 255},
        {  0, 255,   0, 255},
        {  0,   0, 255, 255},
        {255, 255,   0, 255},
        {255,   0, 255, 255},
        {  0, 255, 255, 255},
        {255, 255, 255, 255},
    };
};

#endif // INCLUDE_COLORS_HPP
