#ifndef CONST_H
#define CONST_H

#include <SDL/SDL.h>

#define WINDOW_W 500
#define WINDOW_H 700

#define CELL 50
#define CELL_W WINDOW_W / CELL
#define CELL_H WINDOW_H / CELL

#define NB_CELLS CELL_W * CELL_H

typedef enum Shape Shape;
enum Shape
{
    O,
    I,
    S,
    Z,
    L,
    J,
    T
};

typedef struct Block Block;
struct Block
{
    size_t x;
    size_t y;
    size_t w;
    size_t h;
    Uint32 color;
    Shape shape;
    int grid[4][4];
};

#endif
