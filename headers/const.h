#ifndef CONST_H
#define CONST_H

#include <SDL/SDL.h>

#define WINDOW_W 250
#define WINDOW_H 500

#define CELL 25
#define CELL_W WINDOW_W / CELL
#define CELL_H WINDOW_H / CELL

#define NB_CELLS CELL_W * CELL_H

#define FALL_FREQ 300
#define MOVE_FREQ 150

typedef enum Dir Dir;
enum Dir
{
    RIGHT,
    LEFT,
    NONE
};

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

typedef struct Cell Cell;
struct Cell
{
    int empty;
    Uint32 color;
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
