#include "starmap_main.h"

Star* Stars[15];
Star* currStar;
    
void starmap_init_gfx(void)
{
    // Load Background tiles and then map
    set_bkg_data(0, 592u, StarmapTiles);
    set_bkg_tiles(0, 0, 20u, 18u, Starmap);

    // Turn the background map on to make it visible
    SHOW_BKG;
}

void starmap_init(void)
{
    starmap_init_gfx();
    starmap_init_stars();
    currStar = Stars[0];
    set_sprite_data(0, 584, StarmapTiles);
    set_sprite_tile(0, 0);
}

int starmap_loop(void)
{    
    Star* oldStar = currStar;
    switch (joypad()) {
    case J_B:
        return currStar->id;
        break;
    case J_RIGHT: // If joypad() is equal to RIGHT
        if (currStar->right != NULL)
            currStar = currStar->right;

        break;
    case J_LEFT: // If joypad() is equal to LEFT
        if (currStar->left != NULL)
            currStar = currStar->left;

        break;
    case J_UP: // If joypad() is equal to UP
        if (currStar->top != NULL)
            currStar = currStar->top;

        break;
    case J_DOWN: // If joypad() is equal to DOWN
        if (currStar->down != NULL)
            currStar = currStar->down;

        break;
    }
    move_sprite(0, 8 + (currStar->x * 8), 16 + (currStar->y * 8));


    for (int i = 1; i < 20; i++)
    {
        set_sprite_tile(i, 47);
        move_sprite(i, 8 + (i * 8), 16);
    }

    int i = 0;
    while (currStar->Name[i] != '\0')
    {
        set_sprite_tile(i + 1, currStar->Name[i] - 17);
        i++;
    }

    // Game main loop processing goes here
    SHOW_SPRITES;


    // Done processing, yield CPU and wait for start of next frame
    vsync();
    if (oldStar != currStar)
        delay(500);    
    return -1;
}

void starmap_init_stars(void)
{


    Star* star1 = malloc(sizeof(Star));
    star1->id = 0;
    star1->x = 7;
    star1->y = 1;
    strcpy(star1->Name, "ALMAAK");

    Star* star2 = malloc(sizeof(Star));
    star2->id = 1;
    star2->x = 5;
    star2->y = 3;
    strcpy(star2->Name, "ETAMIN");

    Star* star3 = malloc(sizeof(Star));
    star3->id = 2;
    star3->x = 9;
    star3->y = 3;
    strcpy(star3->Name, "MIRACH");

    Star* star4 = malloc(sizeof(Star));
    star4->id = 3;
    star4->x = 3;
    star4->y = 4;
    strcpy(star4->Name, "CAPELLA");

    Star* star5 = malloc(sizeof(Star));
    star5->id = 4;
    star5->x = 12;
    star5->y = 4;
    strcpy(star5->Name, "ARNEB");

    Star* star6 = malloc(sizeof(Star));
    star6->id = 5;
    star6->x = 18;
    star6->y = 5;
    strcpy(star6->Name, "DENEB");

    Star* star7 = malloc(sizeof(Star));
    star7->id = 6;
    star7->x = 2;
    star7->y = 7;
    strcpy(star7->Name, "RASALHAGUE");

    Star* star8 = malloc(sizeof(Star));
    star8->id = 7;
    star8->x = 7;
    star8->y = 7;
    strcpy(star8->Name, "SPICA");

    Star* star9 = malloc(sizeof(Star));
    star9->id = 8;
    star9->x = 15;
    star9->y = 9;
    strcpy(star9->Name, "REGULUS");

    Star* star10 = malloc(sizeof(Star));
    star10->id = 9;
    star10->x = 4;
    star10->y = 11;
    strcpy(star10->Name, "ENIF");

    Star* star11 = malloc(sizeof(Star));
    star11->id = 10;
    star11->x = 8;
    star11->y = 11;
    strcpy(star11->Name, "CASTOR");

    Star* star12 = malloc(sizeof(Star));
    star12->id = 11;
    star12->x = 1;
    star12->y = 12;
    strcpy(star12->Name, "DIPHDA");

    Star* star13 = malloc(sizeof(Star));
    star13->id = 12;
    star13->x = 12;
    star13->y = 13;
    strcpy(star13->Name, "UNKALHAI");

    Star* star14 = malloc(sizeof(Star));
    star14->id = 13;
    star14->x = 14;
    star14->y = 15;
    strcpy(star14->Name, "POLLUX");

    Star* star15 = malloc(sizeof(Star));
    star15->id = 14;
    star15->x = 3;
    star15->y = 16;
    strcpy(star15->Name, "PLEIONE");

    star1->left = star2;
    star1->right = star3;
    star1->top = NULL;
    star1->down = NULL;

    star2->left = star4;
    star2->right = star3;
    star2->top = star1;
    star2->down = NULL;

    star3->left = star2;
    star3->right = NULL;
    star3->top = star1;
    star3->right = NULL;

    star4->left = star7;
    star4->right = star8;
    star4->top = star2;
    star4->down = star7;

    star5->left = NULL;
    star5->right = star6;
    star5->top = NULL;
    star5->down = NULL;

    star6->left = star5;
    star6->right = NULL;
    star6->top = NULL;
    star6->down = star9;

    star7->left = NULL;
    star7->right = star10;
    star7->top = star4;
    star7->down = star10;

    star8->left = star4;
    star8->right = NULL;
    star8->top = NULL;
    star8->down = star11;

    star9->left = NULL;
    star9->right = star6;
    star9->top = star6;
    star9->down = star14;

    star10->left = star12;
    star10->right = NULL;
    star10->top = star7;
    star10->down = star15;

    star11->left = NULL;
    star11->right = star13;
    star11->top = star8;
    star11->down = NULL;

    star12->left = NULL;
    star12->right = star10;
    star12->top = NULL;
    star12->down = star15;

    star13->left = star11;
    star13->right = star14;
    star13->top = NULL;
    star13->down = star14;

    star14->left = star13;
    star14->right = NULL;
    star14->top = star9;
    star14->down = NULL;

    star15->left = star12;
    star15->right = NULL;
    star15->top = star10;
    star15->down = NULL;

    Stars[0] = star1;
    Stars[1] = star2;
    Stars[2] = star3;
    Stars[3] = star4;
    Stars[4] = star5;
    Stars[5] = star6;
    Stars[6] = star7;
    Stars[7] = star8;
    Stars[8] = star9;
    Stars[9] = star10;
    Stars[10] = star11;
    Stars[11] = star12;
    Stars[12] = star13;
    Stars[13] = star14;
    Stars[14] = star15;
}