#include "SDL/SDL.h"
#include <signal.h>

#include "gui.h"

#define ICON_SIZE 32

static SDL_Surface* image[7];
static SDL_Surface *screen;
static int arena_height, arena_width;

/**
 * @brief An enumeration to represent all symbols.
 *
 * It can be used to ease the readibility of your code.
 *
 */
enum object { BOY, BOY_ON, BOX, BOX_ON, PARK, WALL, EMPTY };

/**
 * @brief The set of `char` values used to represent maps.
 *
 */
static char symbols[] = { '@', '+', '$', '*', '.', '#', ' ' };

/**
 * @brief The locations of the bitmap images to use.
 *
 * The files must be given in the same order as the symbols.
 */
static char* image_filename[] = {
    "images/yoshi-32-worker.bmp",
    "images/yoshi-32-worker-docked.bmp",
    "images/yoshi-32-box.bmp",
    "images/yoshi-32-box-docked.bmp",
    "images/yoshi-32-dock.bmp",
    "images/yoshi-32-wall.bmp",
    "images/yoshi-32-floor.bmp"
};

void GUI_Close(int code) {
    SDL_Quit();
    exit(code);
}

void GUI_Init(char *title, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO)!=0) {
        fprintf(stderr,"Error in SDL_Init : %s\n",SDL_GetError());
        exit(-1);
    }

    screen = SDL_SetVideoMode(width*ICON_SIZE, height*ICON_SIZE, 32, SDL_HWSURFACE);
    if (screen==NULL) {
        fprintf(stderr,"Error, couldn't set %dx%d video mode : %s\n",
                       width*ICON_SIZE, height*ICON_SIZE, SDL_GetError());
        exit(-1);
    }
    SDL_WM_SetCaption(title, NULL);
    SDL_EventState(SDL_KEYDOWN,         SDL_ENABLE);
    SDL_EventState(SDL_QUIT,            SDL_ENABLE);
    SDL_EventState(SDL_SYSWMEVENT,      SDL_ENABLE);
    atexit(SDL_Quit);
    signal(SIGINT,GUI_Close);
    signal(SIGTERM,GUI_Close);

    arena_width = width;
    arena_height = height;

    for (int obj=BOY; obj<=EMPTY; obj++) {
        image[obj] = SDL_LoadBMP(image_filename[obj]);
        if (!image[obj]) {
            fprintf(stderr, "Missing image %s\n", image_filename[obj]);
            exit(1);
        }

    }
}

void GUI_Show(int x, int y, char symbol)
{
    SDL_Rect area = { x * ICON_SIZE, y * ICON_SIZE };
    for (int obj=BOY; obj<=EMPTY; obj++)
        if (symbol == symbols[obj])
            SDL_BlitSurface(image[obj], NULL, screen, &area);
    SDL_Flip(screen);
}

int GUI_GetKey(void)
{
    SDL_Event event;
    do {
        SDL_WaitEvent(&event);
        if (event.type==SDL_QUIT) GUI_Close(0);
    } while (event.type != SDL_KEYDOWN);

    return event.key.keysym.sym;
}

void WaitClick()
{
    SDL_EventState(SDL_MOUSEBUTTONDOWN, SDL_ENABLE);
    SDL_Event event;
    do {
        SDL_WaitEvent(&event);
    } while (event.type!=SDL_MOUSEBUTTONDOWN);
    SDL_EventState(SDL_MOUSEBUTTONDOWN, SDL_IGNORE);
}

void Pause(int time)
{
    SDL_Delay(time);
}
