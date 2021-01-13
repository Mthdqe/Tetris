#include <stdio.h>
#include "../headers/const.h"

void read(Block* block, char* filename)
{
    FILE* f = fopen(filename, "r");

    if (f != NULL)
    {
        for (size_t i = 0; i < block->h; i++)
        {
            for (size_t j = 0; j < block->w; j++)
                fscanf(f, "%d", &block->grid[i][j]);
        }

        fclose(f);
    }

    else
        printf("%s not found\n", filename);
}
