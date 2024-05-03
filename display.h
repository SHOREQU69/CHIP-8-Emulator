#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_video.h>
#include <stdint.h>
#include "SDL2/SDL.h"

typedef uint8_t BYTE;
typedef uint16_t WORD;

/*
 *  handles the display of the CHIP-8
 */

#define DISP_WIDTH 64
#define DISP_HEIGHT 32
#define CELL_SIZE 20

//display elements
typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    BYTE gfx [DISP_WIDTH * DISP_HEIGHT]; //display data
    SDL_Rect map[DISP_WIDTH * DISP_HEIGHT]; //map of rectangles to be rendered
} disp;

//initialise display elements
BYTE init_disp(disp *d);
//get input
void disp_events(BYTE *running);
//clear the screen and render the display data
void render(disp *d);
void disp_close(disp *d);

#endif
