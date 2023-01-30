#include "game/board.hpp"
#include "utils/random.hpp"
#include "game/colors.hpp"
#include <iostream>

using std::cout;
using std::endl;

using game::Board;
using game::Tile;


void Board::generate_tiles()
{
    int size = width * height;
    int max_color = colors_count - 1;

    for(int i = 0; i < size / 2; i++) {
        int color = random(0, max_color);
        for(int j = 0; j < 2; j++) {
            int pos = random(0, size - 1);
            while(data[pos].color != -1)
                pos = (pos + 1) % size;
            data[pos].color = color;
        }
    }

    cout << "Color map: " << endl;
    for(int i = 0; i < size; i++) {
        if(i % width == 0)
            cout << endl;
        cout << (data + i)->color << " ";
    }
    cout << endl;
}
