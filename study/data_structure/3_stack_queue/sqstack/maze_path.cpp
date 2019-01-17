/*======================================================================
*        filename: maze_path.cpp
*        author: rambogui
*        data: 2019-01-17 20:46:09
======================================================================*/

#include <iostream>
#include <cstring>
#include <stdexcept>
#include "sqstack.h"

constexpr unsigned mapstep = 10;

const static unsigned map[mapstep*mapstep] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 1, 0, 0, 0, 1, 0, 1,
    1, 0, 0, 1, 0, 0, 0, 1, 0, 1,
    1, 0, 0, 0, 0, 1, 1, 0, 0, 1,
    1, 0, 1, 1, 1, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 1, 0, 0, 1,
    1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

struct path_node{
    int ord;
    int pos;
    int dir;
};

std::ostream& printfmap(std::ostream &os, const unsigned *map)
{
    std::cout << "  ";
    for (int i = 0; i < mapstep; ++i)
        std::cout << i << ' ';
    std::cout << '\n';

    for (int i = 0; i < mapstep; ++i) {
        for (int j = 0; j < mapstep; ++j) {
            if (j == 0) std::cout << i << ' ';
            os << map[i*mapstep + j] << ' ';
        }
        os << '\n';
    }
    return os;
}

bool curpos_pass(unsigned *map, int pos)
{
    return map[pos] == 0;
}

int next_pos(unsigned *map, int pos, int dir)
{
    if (dir == 1) return pos + 1;
    if (dir == 2) return pos + mapstep;
    if (dir == 3) return pos - 1;
    if (dir == 4) return pos - mapstep;
    throw std::out_of_range(std::string("direct is error"));
}

void make_pos(unsigned *map, int pos)
{
    map[pos] = 2;
}

void maze_path(unsigned *map, stack<path_node> &path, 
    int start = 1*mapstep+1, int end = 8*mapstep+8)
{
    path.reset();
    int curpos = start;
    int step = 1;
    path_node tmp;

    do {
        if (curpos_pass(map, curpos)) {
            tmp.ord = step; tmp.pos = curpos; tmp.dir = 1;
            make_pos(map, curpos);
            path.push(tmp);
            if (curpos == end) return;
            curpos = next_pos(map, tmp.pos, tmp.dir);
            step++;
        } else {
            path.pop(tmp);
            while (tmp.dir == 4 && !path.empty()) { 
                path.pop(tmp);
                step--;
            }
            
            if (tmp.dir < 4) {
                tmp.dir++;
                curpos = next_pos(map, tmp.pos, tmp.dir);
                path.push(tmp);
            }
        }
    } while (!path.empty());
}

void print_path(stack<path_node> &path)
{
    path_node tmp;
    path.pop(tmp);
    if (!path.empty()) 
        print_path(path);
    std::cout << tmp.ord << '(' << tmp.pos/mapstep 
        << ',' << tmp.pos%mapstep << ')' << tmp.dir << ' ';
}

int main(int argc, char *argv[])
{
    printfmap(std::cout, map) << std::endl; 

    unsigned mapcopy[mapstep*mapstep];
    memcpy(mapcopy, map, sizeof(mapcopy));
    stack<path_node> path;
    maze_path(mapcopy, path);
    print_path(path);
    std::cout << std::endl;
    printfmap(std::cout, mapcopy) << std::endl; 
    return 0;
}
