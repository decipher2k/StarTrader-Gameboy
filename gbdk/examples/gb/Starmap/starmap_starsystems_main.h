#ifndef STARMAP_STARSYSTEM_MAIN
#define STARMAP_STARSYSTEM_MAIN 1

#include "starmap_starsystems_main.h"

#include <gb/gb.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern typedef struct Planet Planet;

extern struct Planet
{
	int id;
	char Name[50];
	int TileId;
	int TileWidthHeight;
	
	int x;
	int y;

	Planet* left;
	Planet* right;
	Planet* top;
	Planet* down;
};

extern typedef struct Starsystem Starsystem;

extern struct Starsystem
{
	int id;
	Planet* Planets[5];
	unsigned char *Tileset;
	unsigned char *Tilemap;
};

#endif