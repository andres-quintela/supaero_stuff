/*

   Copyright 1985-2015 Fabrice Frances

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

Short history:
1985: 6502 assembly version
1990: 8086 assembly version
2007: Java version
2015: C + SDL/SDL2 version

*/

#define _POSIX_C_SOURCE 200809L                 \

// Note: change the following #define statement to use the recursive version.
#define RECURSIVE false

// Uncomment the following define to use SDL2.0 instead of SDL1.2
//#define SDL2

#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include "maze.h"

static int step, width, height;
static bool show;
static int window_width, window_height;

static char **map = NULL;
#define ROOM_VISITED 1
#define VERT_WALL 2
#define HORIZ_WALL 4

//enum DIR { RIGHT, SOUTH, WEST, NORTH };

struct direction { int x, y; };
static struct direction directions[]= { {1,0}, {0,1}, {-1,0}, {0,-1} };

/******************************************************************************************
 * Layer 1: Interface to SDL/SDL2
 ******************************************************************************************/

#ifdef SDL2
#include <SDL2/SDL.h>
#else
#include <SDL/SDL.h>
#endif

static SDL_Surface *screen;

#ifdef SDL2
static SDL_Window *window=NULL;
static SDL_Renderer *renderer=NULL;
static void DrawInWhite() { SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0xFF); }
static void DrawInBlack() { SDL_SetRenderDrawColor(renderer,0,0,0,0xFF); }
static void DrawInRed() { SDL_SetRenderDrawColor(renderer,0xFF,0,0,0xFF); }
#else
static unsigned int current_color;
static void DrawInWhite() { current_color=SDL_MapRGB(screen->format,0xFF,0xFF,0xFF); }
static void DrawInBlack() { current_color=SDL_MapRGB(screen->format,0,0,0); }
static void DrawInRed() { current_color=SDL_MapRGB(screen->format,0xFF,0,0); }

/*
 * Set the pixel at (x, y) to the given value
 * NOTE: The surface must be locked before calling this!
 */
static void PutPixel(SDL_Surface *surface, int x, int y, Uint32 color)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
        case 1: *p = color; break;
        case 2: *(Uint16 *)p = color; break;
        case 3:
            if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
                p[0] = (color >> 16) & 0xff;
                p[1] = (color >> 8) & 0xff;
                p[2] = color & 0xff;
            } else {
                p[0] = color & 0xff;
                p[1] = (color >> 8) & 0xff;
                p[2] = (color >> 16) & 0xff;
            }
            break;
        case 4: *(Uint32 *)p = color; break;
    }
}
#endif

static void DrawLine(int x1, int y1, int x2, int y2)
{
#ifdef SDL2
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    if (show) SDL_RenderPresent(renderer);
#else
    if (SDL_MUSTLOCK(screen)) {
	if (SDL_LockSurface(screen) < 0) {
	    fprintf(stderr, "Can't lock screen: %s\n", SDL_GetError());
	    return;
	}
    }
    // limited implementation for vertical/horizontal lines
    if (x1==x2) {
	int y;
	for (y=y1; y<=y2; y++)
	    PutPixel(screen, x1, y, current_color);
    } else {
	int x;
	for (x=x1; x<=x2; x++)
            PutPixel(screen, x, y1, current_color);
    }
    if (SDL_MUSTLOCK(screen))
	SDL_UnlockSurface(screen);
    if (show) SDL_UpdateRect(screen, x1, y1, x2-x1+1, y2-y1+1);
#endif
}

static void FillRect(int x, int y, int width, int height)
{
#ifdef SDL2
    SDL_Rect rect = { x, y, width, height };
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);
#else
    if (SDL_MUSTLOCK(screen)) {
	if (SDL_LockSurface(screen) < 0) {
	    fprintf(stderr, "Can't lock screen: %s\n", SDL_GetError());
	    return;
	}
    }
    // TODO: use BitBlt to speed up big sizes
    int i,j;
    for (i=0; i<width; i++)
	for (j=0; j<height; j++)
            PutPixel(screen,x+i,y+j,current_color);

    if (SDL_MUSTLOCK(screen))
	SDL_UnlockSurface(screen);
    SDL_UpdateRect(screen, x, y, width, height);
#endif
}

static void UpdateScreen()
{
#ifdef SDL2
    SDL_RenderPresent(renderer);
#else
    SDL_UpdateRect(screen, 0, 0, window_width, window_height);
#endif
}

static void SigHandler(int signum)
{
    SDL_Quit();
    exit(signum);
}

static void InitSDL(int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO)!=0) {
        fprintf(stderr,"Error in SDL_Init : %s\n",SDL_GetError());
        exit(-1);
    }

#ifdef SDL2
    window = SDL_CreateWindow("Maze", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              width, height, SDL_WINDOW_SHOWN);

    if (window==NULL) {
        fprintf(stderr,"Error in SDL_CreateWindow : %s\n",SDL_GetError());
        SDL_Quit();
        exit(-1);
    }

    screen = SDL_GetWindowSurface(window);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
#else
    screen = SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE|SDL_ANYFORMAT);
    if (screen==NULL) {
	fprintf(stderr,"Error, couldn't set %dx%d video mode : %s\n",
			window_width, window_height, SDL_GetError());
	exit(-1);
    }
    SDL_WM_SetCaption("Maze",NULL);
#endif

    // pas de polling des events, alors essayons de ne pas avoir d'event dans la file
    // devant un Ctrl-C
    SDL_EventState(SDL_KEYDOWN,         SDL_IGNORE);
    SDL_EventState(SDL_KEYUP,           SDL_IGNORE);
    SDL_EventState(SDL_MOUSEMOTION,     SDL_IGNORE);
    SDL_EventState(SDL_MOUSEBUTTONDOWN, SDL_IGNORE);
    SDL_EventState(SDL_MOUSEBUTTONUP,   SDL_IGNORE);
    SDL_EventState(SDL_SYSWMEVENT,      SDL_IGNORE);
#ifdef SDL2
    SDL_EventState(SDL_MOUSEWHEEL,      SDL_IGNORE);
    SDL_EventState(SDL_WINDOWEVENT,     SDL_IGNORE);
    SDL_EventState(SDL_TEXTEDITING,     SDL_IGNORE);
    SDL_EventState(SDL_TEXTINPUT,       SDL_IGNORE);
#else
    SDL_EventState(SDL_VIDEORESIZE,	SDL_IGNORE);
    SDL_EventState(SDL_VIDEOEXPOSE,	SDL_IGNORE);
    SDL_EventState(SDL_ACTIVEEVENT,	SDL_IGNORE);
#endif
    signal(SIGINT,SigHandler);
    signal(SIGTERM,SigHandler);

    window_width = width;
    window_height = height;
}

static void TerminateSDL()
{
#ifdef SDL2
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
#endif
    SDL_Quit();
}

/**********************************************************************************************
 * Layer 2: the wall routines
 **********************************************************************************************/

static void AllocateMap(int width, int height)
{
    int i;
    map = calloc(width+2,sizeof(char *));
    if (map==NULL) { fprintf(stderr,"calloc : not enough memory !\n"); exit(-1); }
    for (i=0; i<width+2; i++) {
        map[i] = malloc(height+2);
        if (map[i]==NULL) { fprintf(stderr,"calloc : not enough memory !\n"); exit(-1); }
    }
}

static void FreeMap()
{
    int i;
    for (i=0; i<width+2; i++)
        free(map[i]);
    free(map);
}

static void BuildVertWall(int x, int y)
{
    map[x][y] |= VERT_WALL;
    DrawInWhite();
    DrawLine(x*step, y*step, x*step, y*step+step);
}

static void BuildHorizWall(int x, int y)
{
    map[x][y] |= HORIZ_WALL;
    DrawInWhite();
    DrawLine(x*step, y*step, x*step+step, y*step);
}

static void RemoveHorizWall(int x, int y)
{
    map[x][y] &= ~HORIZ_WALL;
    DrawInBlack();
    DrawLine(x*step+1, y*step, x*step+step-1, y*step);
}

static void RemoveVertWall(int x, int y)
{
    map[x][y] &= ~VERT_WALL;
    DrawInBlack();
    DrawLine(x*step, y*step+1, x*step, y*step+step-1);
}

static void InitMap()
{
    int x, y;
    for (y=0; y<height+2; y++)
        for (x=0; x<width+2; x++)
            map[x][y]=0;

    for (x=0; x<width+2; x++) {
        map[x][0] |= ROOM_VISITED;
        map[x][height+1] |= ROOM_VISITED;
    }
    for (y=0; y<height+2; y++) {
        map[0][y] |= ROOM_VISITED;
        map[width+1][y] |= ROOM_VISITED;
    }
}

static int Wall(int x, int y, enum Direction dir)
{
    switch(dir) {
        case EAST: return map[x+1][y] & VERT_WALL;
        case SOUTH: return map[x][y+1] & HORIZ_WALL;
        case WEST: return map[x][y] & VERT_WALL;
        case NORTH : return map[x][y] & HORIZ_WALL;
	default: return 0;
    }
}

static void BuildWall(int x, int y, enum Direction dir)
{
    switch (dir) {
        case EAST: BuildVertWall(x+1, y); break;
        case SOUTH: BuildHorizWall(x, y+1); break;
        case WEST: BuildVertWall(x, y); break;
        case NORTH: BuildHorizWall(x, y); break;
    }
}

static bool AllNeighborsVisited(int x, int y)
{
    return (map[x+1][y] & map[x-1][y] & map[x][y-1] & map[x][y+1] & ROOM_VISITED) != 0;
}


/*************************************************************************************************
 * Layer 3: the Maze generation
 *************************************************************************************************/

// routine de remplissage par une marche aléatoire,
// on construit les murs autour des couloirs arpentés par la marche aléatoire

#if RECURSIVE
static void FillMap(int x, int y, int dir)
{
    map[x][y] |= ROOM_VISITED;
    // construit les murs pour séparer les lieux adjacents déjà visités,
    // sauf celui qui séparerait la pièce d'où l'on vient
    int d, opposite_dir = (dir+2)%4;
    for (d=0; d<4; d++)
        if (d!=opposite_dir && map[x+directions[d].x][y+directions[d].y]&ROOM_VISITED)
            BuildWall(x, y, d);
    // explore récursivement les voisins, dans un ordre aléatoire
    while (!AllNeighborsVisited(x, y)) {
        // choisit un lieu voisin non visité, au hasard
        dir=rand()%4;
        while (map[x+directions[dir].x][y+directions[dir].y]&ROOM_VISITED)
            dir=rand()%4;
        // remplit à partir du voisin choisi
        FillMap(x+directions[dir].x, y+directions[dir].y, dir);
    }
}
#else
static void FillMap(int size, int x, int y)
{
    map[x][y] |= ROOM_VISITED;

    int n, dir=0;
    for (n=1; n<size; n++) {

        // on peut tomber sur une impasse avant d'avoir tout rempli
        // (parce que la marche s'est entortillée sur elle-même)
        // Pour éviter la récursivité, on fait la main au mur pour
        // revenir en arrière quand on remplit une impasse
        while (AllNeighborsVisited(x, y)) {
            if (Wall(x, y, (dir+3)%4)) {
              if (Wall(x, y, dir)) {
                 dir = (dir+1)%4;
              } else {
                 x += directions[dir].x;
                 y += directions[dir].y;
              }
            } else {
              dir = (dir+3)%4;
              x += directions[dir].x;
              y += directions[dir].y;
            }
        }

        // choisit une direction ouverte au hasard
        dir=rand()%4;
        while (map[x+directions[dir].x][y+directions[dir].y]&ROOM_VISITED)
            dir=rand()%4;

        // part dans la direction choisie, marque le lieu
        x += directions[dir].x;
        y += directions[dir].y;
        map[x][y] |= ROOM_VISITED;

        // construit les murs pour séparer les lieux adjacents déjà visités,
        // sauf celui qui séparerait la pièce d'où l'on vient
        int d, opposite_dir = (dir+2)%4;
        for (d=0; d<4; d++)
            if (d!=opposite_dir && map[x+directions[d].x][y+directions[d].y]&ROOM_VISITED)
              BuildWall(x, y, d);
    }
}
#endif

static void BuildMaze(long seed)
{
    InitMap();
    srand(seed);
    int x_start = 1 + width/4 + rand()%(width/2);
    int y_start = 1 + height/4 + 1 + rand()%(height/4);
#if RECURSIVE
    FillMap(x_start, y_start, 0);
#else
    FillMap(width*height, x_start, y_start);
#endif
}

/***********************************************************************************************/
/* Modification du labyrinthe pour introduire un circuit central et un circuit sur le bord     */
/***********************************************************************************************/

// Avant d'enlever un mur vertical et pour éviter de laisser un carré de 4 cases vide,
// teste les trois autres murs connectés au poteau du haut
// et les trois connectés au poteau du bas
static bool VerticalConnected(int x, int y)
{
     return (Wall(x, y-1, WEST) || Wall(x, y, NORTH) || Wall(x-1, y, NORTH))
             && (Wall(x, y+1, WEST) || Wall(x, y, SOUTH) || Wall(x-1, y, SOUTH));
}

// Avant d'enlever un mur horizontal et pour éviter de laisser un carré de 4 cases vide,
// teste les trois autres murs connectés au poteau de gauche
// et les trois connectés au poteau de droite
static bool HorizontalConnected(int x, int y)
{
     return (Wall(x-1, y, NORTH) || Wall(x, y, WEST) || Wall(x, y-1, WEST))
             && (Wall(x+1, y, NORTH) || Wall(x, y, EAST) || Wall(x, y-1, EAST));
}

static void MakeCentralIsland()
{
    int x, y;
    for (x=1+width/4; x<=1+3*width/4; x++) {
        if (VerticalConnected(x, 1+height/4))
            RemoveVertWall(x, 1+height/4);
        if (VerticalConnected(x, 1+3*height/4))
            RemoveVertWall(x, 1+3*height/4);
    }
    for (y=1+height/4; y<=1+3*height/4; y++) {
        if (HorizontalConnected(1+width/4, y))
            RemoveHorizWall(1+width/4, y);
        if (HorizontalConnected(1+3*width/4, y))
            RemoveHorizWall(1+3*width/4, y);
    }
}

/***************************************************************************************************************************
 * Layer 2: Bob the robot routines
 **************************************************************************************************************************/

static int x_bob, y_bob, bob_speed=100;

void BobSetSpeed(unsigned speed) { bob_speed = speed; }

static void BobShow()
{
    DrawInRed();
    FillRect(x_bob, y_bob, step-1, step-1);
}

static void BobHide()
{
    DrawInBlack();
    FillRect(x_bob, y_bob, step-1, step-1);
}

static void PixelPause(unsigned int speed)
{
    struct timespec requested_time, remaining;
    requested_time.tv_sec = 0;
    requested_time.tv_nsec = 1000000000/(speed+1);
    nanosleep(&requested_time, &remaining);
}

/***********************************************************************************************/
/* Les fonctions externes utilisables                                                          */
/***********************************************************************************************/

void MazeInit(int horizontal_size, int vertical_size, int corridor_size, long maze_id, bool tree, bool show_build)
{
    if (corridor_size<=0 || corridor_size>500 || horizontal_size<1 || vertical_size<1)
        return;
    width = horizontal_size;
    height = vertical_size;
    step = corridor_size+1;
    show = show_build;
    int window_width = step*(width+2)+1;
    int window_height = step*(height+2)+1;
    if (screen) MazeEnd();
    InitSDL(window_width, window_height);
    AllocateMap(width, height);
    BuildMaze(maze_id);
    if (!tree) MakeCentralIsland();
    RemoveHorizWall(width/2+1, 1); // la sortie
    // bob au milieu
    x_bob = (width/2+1)*step+1;
    y_bob = (height/2+1)*step+1;
    BobShow();
    UpdateScreen();
}

void MazeEnd()
{
    if (map!=NULL) FreeMap();
    TerminateSDL();
}

bool BobIsOut()
{
    return x_bob<step || x_bob>=(width+2)*step || y_bob<step || y_bob>=(height+2)*step;
}

bool BobHasWestContact()
{
    if (y_bob%step!=1) return true;  // on touche forcément un poteau
    if (y_bob<step || y_bob>=(height+2)*step) return false;
    if (x_bob<step || x_bob>=(width+2)*step || x_bob%step!=1) return false;
    return Wall(x_bob/step,y_bob/step,WEST);
}

bool BobHasEastContact()
{
    if (y_bob%step!=1) return true;
    if (x_bob<0 || x_bob>=(width+1)*step || x_bob%step!=1) return false;
    if (y_bob<step || y_bob>=(height+2)*step) return false;
    return Wall(x_bob/step,y_bob/step,EAST);
}

bool BobHasNorthContact()
{
    if (x_bob%step!=1) return true;
    if (x_bob<step || x_bob>=(width+2)*step) return false;
    if (y_bob<step || y_bob>=(height+2)*step || y_bob%step!=1) return false;
    return Wall(x_bob/step,y_bob/step,NORTH);
}

bool BobHasSouthContact()
{
    if (x_bob%step!=1) return true;
    if (x_bob<step || x_bob>=(width+2)*step) return false;
    if (y_bob<0 || y_bob>=(height+1)*step || y_bob%step!=1) return false;
    return Wall(x_bob/step,y_bob/step,SOUTH);
}

void BobGoWest()
{
    int i;
    if (BobHasWestContact()) return;
    for (i=0; i<step; i++) {
        BobHide();
        x_bob--;
        BobShow();
        PixelPause(bob_speed);
    }
}

void BobGoEast()
{
    int i;
    if (BobHasEastContact()) return;
    for (i=0; i<step; i++) {
        BobHide();
        x_bob++;
        BobShow();
        PixelPause(bob_speed);
    }
}

void BobGoNorth()
{
    int i;
    if (BobHasNorthContact()) return;
    for (i=0; i<step; i++) {
        BobHide();
        y_bob--;
        BobShow();
        PixelPause(bob_speed);
    }
}

void BobGoSouth()
{
    int i;
    if (BobHasSouthContact()) return;
    for (i=0; i<step; i++) {
        BobHide();
        y_bob++;
        BobShow();
        PixelPause(bob_speed);
    }
}

// fonctions relatives aux directions
enum Direction TurnTo(enum Direction current_dir,
                      enum RelativeDirection relative_dir)
{
    return (current_dir+relative_dir+4)%4;
}


void OneStepForward(enum Direction current_dir)
{
    switch (current_dir) {
        case EAST:  BobGoEast();    break;
        case SOUTH: BobGoSouth();   break;
        case WEST:  BobGoWest();    break;
        case NORTH: BobGoNorth();   break;
    }
}

bool RelativeContact(enum Direction current_dir,
                     enum RelativeDirection relative_dir)
{
    bool contact = false;
    switch (TurnTo(current_dir, relative_dir)) {
        case EAST:  contact = BobHasEastContact();  break;
        case SOUTH: contact = BobHasSouthContact(); break;
        case WEST:  contact = BobHasWestContact();  break;
        case NORTH: contact = BobHasNorthContact(); break;
    }
    return contact;
}
