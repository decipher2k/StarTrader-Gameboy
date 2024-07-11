#include "starsystem_main.h"
//#include "../res/starmap_background.h"

#include <gbdk/platform.h>
#include <stdint.h>
#include <stdio.h>
/*
#include "musicmanager.h"
#include "hUGEDriver.h"
*/


void starsystem_init_gfx(void)
{
    HIDE_SPRITES;
  //  memset(BG_MAP, 0, 32 * 32);
    
    
    
    set_bkg_data(0, 37u, StarsystemTiles);
    set_bkg_tiles(0, 0, 20u, 18u, Starsystem);

    // Turn the background map on to make it visible
    SHOW_BKG;



}

void starsystem_init(void)
{
    starsystem_init_gfx();
    
    // Load Background tiles and the
    NR52_REG = 0x80; // is 1000 0000 in binary and turns on sound
    NR50_REG = 0x77; // sets the volume for both left and right channel just set to max 0x77
    NR51_REG = 0xFF; // is 1111 1111 in binary, select which chanels we want to use in this case all of them. One bit for the L one bit for the R of all four channels
    /*
    static uint8_t music_paused = FALSE;

    // initialize the music and SFX driver
    music_init();

    CRITICAL{
        // set up the game boy timer
        music_setup_timer();
    // add music and SFX driver ISR to the low priority timer chain
    add_low_priority_TIM(music_play_isr);
    }
        // enable the timer interrupt
    set_interrupts(IE_REG | TIM_IFLAG);
    music_load(BANK(StarSelect), (const struct hUGESong_t * )&StarSelect), music_pause(music_paused = FALSE);
    */
}

int starsystem_loop(void)
{

    
        move_sprite(0, 1,1);
        switch (joypad()) {
        case J_START:                     
            return 1;
        case J_A:
            delay(500);            
            break;
        case J_RIGHT: // If joypad() is equal to RIGHT
            delay(500);
            break;
        case J_LEFT: // If joypad() is equal to LEFT
            delay(500);
            break;
        case J_UP: // If joypad() is equal to UP
            delay(500);
            break;
        case J_DOWN: // If joypad() is equal to DOWN
            delay(500);
            break;
        }
    // Game main loop processing goes here
    SHOW_SPRITES;
    vsync();
    delay(500);
    return -1;
}