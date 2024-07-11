#include <gb/gb.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "starmap_main.h"
#include "../../Planetsystem/starsystem_main.h"


enum ESCENES {
    SCENE_STARMAP = 1,
    SCENE_PLANETSYSTEM=2
};

//typedef enum SCENES SCENES;


void main(void)
{
    volatile int currentScene = SCENE_STARMAP;

    while (TRUE)
    {

        if (currentScene == SCENE_STARMAP)
        {
            volatile int starSelected = -1;

            starmap_init();
            while (starSelected == -1) {
                starSelected = starmap_loop();
            }
            currentScene = SCENE_PLANETSYSTEM;
        }
        else if (currentScene == SCENE_PLANETSYSTEM)
        {
            volatile int starsystemRet = -1;
            starsystem_init();
            while (starsystemRet == -1) {
                starsystemRet = starsystem_loop();
            }
            if (starsystemRet == 1)
                currentScene = SCENE_STARMAP;
        }
    }
}
