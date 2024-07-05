#ifndef STARMAP_MAIN
#define STARMAP_MAIN 1

#include <gb/gb.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../res/Starmap.h"
#include "../res/StarmapTiles.h"

extern typedef struct Star Star;

extern struct Star {
    int id;
    char Name[50];
    uint16_t x;
    uint16_t y;
    Star* left;
    Star* right;
    Star* top;
    Star* down;
};

extern Star* Stars[15];
extern Star* currStar;

extern void starmap_init(void);
extern void starmap_init_gfx(void);
extern void starmap_init_stars(void);

extern int starmap_loop(void);



#endif