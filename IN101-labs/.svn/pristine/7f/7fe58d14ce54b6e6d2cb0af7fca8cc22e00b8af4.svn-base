/*

   Copyright 2015 Fabrice Frances
   This work is free. You can redistribute it and/or modify it under the
   terms of the Do What The Fuck You Want To Public License, Version 2,
   as published by Sam Hocevar. See http://www.wtfpl.net/ for more details

*/

// Uncomment the following define to use SDL2.0 instead of SDL1.2,
// or add -DSDL2 to the compile line
//#define SDL2

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <signal.h>
#include "space.h"

static int window_width, window_height;

/******************************************************************************************
 * Layer 1: Interface to SDL/SDL2
 ******************************************************************************************/

#ifdef SDL2
#include <SDL2/SDL.h>
static SDL_Renderer *renderer;
static SDL_Window *window;
#else
#include <SDL/SDL.h>
#endif

static SDL_Surface *screen;
static const int MAX_INTENSITY = 255;

/*
 * Add intensity to the existing intensity value of pixel at (x, y)
 * NOTE: The surface must be locked before calling this!
 */
static void IntensifyPixel(int x, int y, int white_intensity)
{
    int bpp = screen->format->BytesPerPixel;
    y = window_height-1 - y;    // reverse y so that 0 is at the bottom of the window
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)screen->pixels + y * screen->pitch + x * bpp;

    switch(bpp) {
        case 1:
        case 2:
            fprintf(stderr,"Please switch to 24 or 32 bits per pixel\n");
            SDL_Quit();
            exit(-1);
        case 3:
        case 4:
            // TODO: find a better intensity sum function
            white_intensity += *p;
            if (white_intensity>MAX_INTENSITY) white_intensity=MAX_INTENSITY;
            p[0]=p[1]=p[2]=white_intensity;
            break;
    }
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

static void InitSDL(char *title, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO)!=0) {
        fprintf(stderr,"Error in SDL_Init : %s\n",SDL_GetError());
        exit(-1);
    }

#ifdef SDL2
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
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
    SDL_WM_SetCaption(title, NULL);
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
    SDL_EventState(SDL_VIDEORESIZE,    SDL_IGNORE);
    SDL_EventState(SDL_VIDEOEXPOSE,    SDL_IGNORE);
    SDL_EventState(SDL_ACTIVEEVENT,    SDL_IGNORE);
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

/*******************************************************************************
 * Layer 2: Playing on intensity to draw points
 *******************************************************************************/

static double fpart(double x) { return x<0 ? 1-(x-floor(x)) : x-floor(x); }
static double rfpart(double x) { return 1 - fpart(x); }

static int Intensity(double intensity)
{
    // TODO: add a good intensity converter
    // this one found empirically by looking at my monitor
    return (int)(MAX_INTENSITY*pow(intensity,1.0/3));
}

static void DrawPoint(double x, double y)
{
    IntensifyPixel((int)x,   (int)y,   Intensity(rfpart(x)*rfpart(y)));
    IntensifyPixel((int)x+1, (int)y,   Intensity( fpart(x)*rfpart(y)));
    IntensifyPixel((int)x,   (int)y+1, Intensity(rfpart(x)* fpart(y)));
    IntensifyPixel((int)x+1, (int)y+1, Intensity( fpart(x)* fpart(y)));
}

/********************************************************************************************
 * Simple Bresenham algorithm, implemented with integers
 ********************************************************************************************/

// static const int OPAQUE_WHITE = 0xFFFFFFFF;

void PlotBresenhamLine(int x1, int y1, int x2, int y2)
{
    // Eventually swap x and y, so that x grows faster than y
    bool xy_swapped = abs(y2-y1) > abs(x2-x1);
    if (xy_swapped) { double t=x1; x1=y1; y1=t;  t=x2; x2=y2; y2=t; }
    // Eventually swap the two points so that x grows from x1 to x2
    if (x1>x2) { double t=x1; x1=x2; x2=t;  t=y1; y1=y2; y2=t; }
    int err = x2 - x1;
    int dx = err * 2, dy = abs(y2-y1) * 2;
    int x, y, y_incr = y2>y1 ? +1 : -1;
    if (xy_swapped) {
        for (x = x1, y = y1; x<=x2; x++) {
            IntensifyPixel(y, x, MAX_INTENSITY);
            if ((err=err-dy) <= 0) { y += y_incr; err += dx; }
        }
    } else {
        for (x = x1, y = y1; x<=x2; x++) {
            IntensifyPixel(x, y, MAX_INTENSITY);
            if ((err=err-dy) <= 0) { y += y_incr; err += dx; }
        }
    }
}

/*****************************************************************************************
 * Gupta-Sproull algorithm,
 * adapted from the book "Computer Graphics: Principles and Practice", 2nd Edition.
 *
 *****************************************************************************************/
static int DistanceIntensity(double distance)
{
    distance = fabs(distance);
    // TODO: add a good intensity converter
    // this one found empirically by looking at my monitor
    int intensity = distance==0 ? MAX_INTENSITY : (int)(100*1.5/distance);
    return intensity;
}

void DrawGuptaSproullLine(int x0, int y0, int x1, int y1)
{
    bool dy_is_bigger = abs(y1-y0) > abs(x1-x0);
    if (dy_is_bigger) { double t=x0; x0=y0; y0=t;  t=x1; x1=y1; y1=t; }
    int dx = abs(x1-x0), dy = abs(y1-y0);
    if (x0>x1) { double t=x0; x0=x1; x1=t;  t=y0; y0=y1; y1=t; }
    double invDenom = 1.0 / (2.0*sqrt(dx*dx + dy*dy));    // Precomputed inverse denominator
    int x, y;
    int incr_y = y0<y1 ? +1 : -1;

    int d = 2*dy - dx;
    int straight_increment = 2*dy, diagonal_increment = 2*(dy-dx);
    int two_v_dx = 0;                                    // Numerator; v=0 for start pixel
    double two_dx_invDenom = 2.0*dx*invDenom;            // Precomputed constant
    for (x=x0, y=y0; x <= x1; x++) {
        if (dy_is_bigger) {
            IntensifyPixel(y+incr_y, x, DistanceIntensity(two_dx_invDenom - two_v_dx*invDenom));
            IntensifyPixel(y-incr_y, x, DistanceIntensity(two_dx_invDenom + two_v_dx*invDenom));
            IntensifyPixel(y,        x, DistanceIntensity(two_v_dx*invDenom));
        } else {
            IntensifyPixel(x, y+incr_y, DistanceIntensity(two_dx_invDenom - two_v_dx*invDenom));
            IntensifyPixel(x, y-incr_y, DistanceIntensity(two_dx_invDenom + two_v_dx*invDenom));
            IntensifyPixel(x, y,        DistanceIntensity(two_v_dx*invDenom));
        }
        if (d < 0) {                                    // Choose straight neighbor
            two_v_dx = d + dx;
            d += straight_increment;
        } else {                                        // Choose diagonal neighbor
            two_v_dx = d - dx;
            d += diagonal_increment;
            y += incr_y;
        }
    }
}

/************************************************************************************************
 * Xiaolin Wu's algorithm, adapted from Wikipedia.
 ************************************************************************************************/
void DrawWuLine(double x0, double y0, double x1, double y1)
{
    bool dy_is_bigger = fabs(y1-y0) > fabs(x1-x0);
    if (dy_is_bigger) { double t=x0; x0=y0; y0=t;  t=x1; x1=y1; y1=t; }
    if (x0>x1) { double t=x0; x0=x1; x1=t;  t=y0; y0=y1; y1=t; }

    double dx = x1-x0,  dy = y1-y0;
    double gradient = dy/dx;

    // handle first endpoint
    double xend = (int)(x0+0.5);
    double yend = y0 + gradient*(xend-x0);
    double xgap = rfpart(x0+0.5);
    int x_pixel1 = (int)xend;
    int y_pixel1 = (int)yend;
    if (dy_is_bigger) {
        IntensifyPixel(y_pixel1,   x_pixel1, Intensity(rfpart(yend)*xgap));
        IntensifyPixel(y_pixel1+1, x_pixel1, Intensity( fpart(yend)*xgap));
    } else {
        IntensifyPixel(x_pixel1, y_pixel1,   Intensity(rfpart(yend)*xgap));
        IntensifyPixel(x_pixel1, y_pixel1+1, Intensity( fpart(yend)*xgap));
    }
    double inter_y = yend + gradient; // first y-intersection

    // handle second endpoint
    xend = (int)(x1+0.5);
    yend = y1 + gradient*(xend-x1);
    xgap = fpart(x1+0.5);
    int x_pixel2 = (int)xend;
    int y_pixel2 = (int)yend;
    if (dy_is_bigger) {
        IntensifyPixel(y_pixel2,   x_pixel2, Intensity(rfpart(yend)*xgap));
        IntensifyPixel(y_pixel2+1, x_pixel2, Intensity( fpart(yend)*xgap));
    } else {
        IntensifyPixel(x_pixel2, y_pixel2,   Intensity(rfpart(yend)*xgap));
        IntensifyPixel(x_pixel2, y_pixel2+1, Intensity( fpart(yend)*xgap));
    }

    // pixel loop
    int x;
    for (x=x_pixel1+1; x < x_pixel2; x++) {
        if (dy_is_bigger) {
            IntensifyPixel((int)inter_y,   x, Intensity(rfpart(inter_y)));
            IntensifyPixel((int)inter_y+1, x, Intensity( fpart(inter_y)));
        } else {
            IntensifyPixel(x, (int)inter_y,   Intensity(rfpart(inter_y)));
            IntensifyPixel(x, (int)inter_y+1, Intensity( fpart(inter_y)));
        }
        inter_y += gradient;
    }
}

/******************************************************************************************
 * "High level" functions for the Convex Hull exercise
 ******************************************************************************************/

void DrawLine(double x0, double y0, double x1, double y1, enum line_algo algo)
{
    switch (algo) {
        case BRESENHAM: PlotBresenhamLine((int)(x0+0.5), (int)(y0+0.5), (int)(x1+0.5), (int)(y1+0.5)); break;
        case GUPTA_SPROULL: DrawGuptaSproullLine((int)(x0+0.5), (int)(y0+0.5), (int)(x1+0.5), (int)(y1+0.5)); break;
        case WU: DrawWuLine(x0, y0, x1, y1); break;
    }
    UpdateScreen();
}


void CreateWindow(int width, int height)
{
    window_width = width;
    window_height = height;
    InitSDL("In a galaxy far far away...", window_width, window_height);
}

void EmptySpace()
{
    SDL_Rect all = { 0, 0, window_width, window_height };
    SDL_FillRect(screen, &all, 0xFF000000);
}

void PlotPixels(double x_pos[], double y_pos[], int nb)
{
    int i;
    for (i=0; i<nb; i++)
        IntensifyPixel((int)(x_pos[i]+0.5), (int)(y_pos[i]+0.5), MAX_INTENSITY);
    UpdateScreen();
}

void DrawPoints(double x_pos[], double y_pos[], int nb)
{
    int i;
    for (i=0; i<nb; i++)
        DrawPoint(x_pos[i], y_pos[i]);
    UpdateScreen();
}

void GenerateSquare(double x_pos[], double y_pos[], int nb, unsigned int seed)
{
    srand(seed);

    for (int i = 0; i < nb; i++) {
        x_pos[i] = rand() % window_width;
        y_pos[i] = rand() % window_height;
    }
}

void GenerateGalaxy(double x_pos[], double y_pos[], int nb, unsigned int seed)
{
    int i;
    srand(seed);
    const double MAX_RADIUS = (window_width<window_height ? window_width : window_height)/2 - 10;
    for (i=0; i<nb; i++) {
        double radius = 0;
        while (radius<1E-8)
            radius = MAX_RADIUS*exp(-rand()/(RAND_MAX/30.0));
        double angle = rand();
        x_pos[i] = window_width/2 + radius*cos(angle);
        y_pos[i] = window_height/2 + radius*sin(angle);
    }
}

void DrawConvexHull(double x[], double y[], int nb_points, int nb_hull_points)
{
    EmptySpace();
    int i;
    for (i=0; i<nb_points; i++)
        IntensifyPixel((int)(x[i]+0.5), (int)(y[i]+0.5), MAX_INTENSITY);
    for (int i=0; i<nb_hull_points-1; i++)
         DrawWuLine(x[i], y[i], x[i+1], y[i+1]);
    // draw segment between last and first points to close the polygon
    DrawWuLine(x[nb_hull_points-1], y[nb_hull_points-1], x[0], y[0]);
    UpdateScreen();
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

void CloseWindow() { TerminateSDL(); }
