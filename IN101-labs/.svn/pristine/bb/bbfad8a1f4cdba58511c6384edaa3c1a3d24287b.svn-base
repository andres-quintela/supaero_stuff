/*
 *
 *    Copyright 2015 Fabrice Frances
 *
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.
 */

/**
 * @file space.h
 * @brief A long time ago, in a galaxy far, far away...
 *
 * This module exposes a number of line drawing algorithms,
 * and a few functions to support the Convex Hull exercise.
 *
 * @see https://en.wikipedia.org/wiki/Line_drawing_algorithm
 *
 * Use -lm -lSDL when compiling in order to link with math library and SDL library.
 *
 * <B>Trivia</B>: Do you know that the first displays were very different than the ones
 * you are using nowadays ? Like the first oscilloscopes' displays, a magnetic field was used
 * to drive the electron beam so that vectors were drawn with a regular width (except on both
 * ends of segments where a point of higher intensity could be seen).
 * Later, the magnetic field was programmed to always follow the same pattern known as "raster".
 * This introduced rasterization problems modern displays have to deal with,
 * showing ugly aliasing when displaying vector graphics.
 * Airline pilots too were used to the vector graphics, and they refused low-quality raster
 * graphics, pushing the aircraft suppliers to manufacture high-resolution raster displays
 * and use anti-aliasing techniques to give the feel of the old vector displays...
 *
 * @see https://en.wikipedia.org/wiki/Spacewar_%28video_game%29
 *
 * and if you want to have a vector display at home, try to find a Vectrex console ;-)
 * @see https://en.wikipedia.org/wiki/Vectrex
 *
 * @author Fabrice Frances
 * @date 7 Dec 2015
 */




/**
 * This function creates a SDL window
 *
 * @param width the window width (in pixels)
 * @param height the window height (in pixels)
 */
extern void CreateWindow(int width, int height);

/**
 * This function terminates the graphical program
 */
extern void CloseWindow(void);

/**
 * This function waits for a mouse click in the SDL window.
 *
 * This is useful for pausing your program without having the cpu run at 100%...
 */
extern void WaitClick(void);

/**
 * This function plots a number of pixels.
 *
 * For each couple of coordinates given by the parameters, the closest pixel will be plotted
 * (ie. floating point coordinates are rounded to the closest integer).
 *
 *
 * @param x_pos the array of X-coordinates
 * @param y_pos the array of Y-coordinates
 * @param nb the number of pixels to plot.
 * Caution: the number of elements in the two coordinate arrays must be large enough so that accessing this number of
 * pixels will not exceed the arrays' size.
 *
 */
extern void PlotPixels(double x_pos[], double y_pos[], int nb);

/**
 * This function draws a number of points.
 *
 * Coordinates of points might not be integer, so this function will try to rasterize the point intensity
 * to four neighbor pixels.
 *
 *
 * @param x_pos the array of X-coordinates
 * @param y_pos the array of Y-coordinates
 * @param nb the number of points to draw.
 * Caution: the number of elements in the two coordinate arrays must be large enough so that accessing this number of
 * points will not exceed the arrays' size.
 *
 */
extern void DrawPoints(double x_pos[], double y_pos[], int nb);

/**
 * This function plots a segment, using the Bresenham algorithm.
 *
 * This is the classic Bresenham algorithm, expressed with integer variables only.
 * @see https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm for more details.
 *
 * @param x0,y0 the coordinates of the first end of the segment
 * @param x1,y1 the coordinates of the second end of the segment
 */
extern void PlotBresenhamLine(int x0, int y0, int x1, int y1);

/**
 * This function draws a segment, using the Gupta-Sproull algorithm.
 *
 * Satish Gupta and Robert Sproull published their paper entitled
 * "Filtering edges for gray-scale displays" in ACM SIGGRAPH ’81
 * (Proceedings: 1–5. ACM Press, Dallas 1981, ISBN 0-89791-045-1)
 *
 * A description of their algorithm can also be read in the following book :
 * "Computer Graphics: Principles and Practice", available at the ISAE library...
 *
 * @param x0,y0 the coordinates of the first end of the segment
 * @param x1,y1 the coordinates of the second end of the segment
 */
extern void DrawGuptaSproullLine(int x0, int y0, int x1, int y1);

/**
 * This function draws a segment, using Xiaolin Wu's algorithm.
 *
 * @see https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
 *
 * @param x0,y0 the coordinates of the first end of the segment
 * @param x1,y1 the coordinates of the second end of the segment
 */
extern void DrawWuLine(double x0, double y0, double x1, double y1);


/**
 * This enumeration lists three line-drawing algorithms.
 *
 * Do better than these three algorithms (e.g. using sub-pixel rasterization) and add your name here !
 */
enum line_algo { BRESENHAM, GUPTA_SPROULL, WU };

/**
 * This function draws a line, using one of three algorithms.
 *
 * You can compare the visual appearance of these three algorithms: draw lines of various angles and see
 * how the simple Bresenham algorithm might exhibit staircase-like effect.
 * Gupta-Sproull and Wu's algorithms try to reduce this effect with anti-aliasing techniques,
 * adjusting the intensity of neighbor pixels.
 *
 * Add your own (better) algorithm using sub-pixel rasterization!
 *
 * @param x0,y0 the coordinates of the first end of the segment
 * @param x1,y1 the coordinates of the second end of the segment
 * @param algo an algorithm from the enum line_algo .
 * @see enum line_algo
 */
extern void DrawLine(double x0, double y0, double x1, double y1, enum line_algo algo);

/**
 * This function generates random points.
 *
 * This function will store Cartesian random coordinate points in the two arrays x_pos and y_pos.
 * Points are chosen randomly in the rectangle represented by the window height and width.
 *
 * @param x_pos the array to store the X-coordinates of the points
 * @param y_pos the array to store the Y-coordinates of the points
 * @param nb the number of points to store in the arrays.
 * Caution: this number must not be larger than the size of the arrays.
 * @param seed a number identifying each random generation.
 * You will reproduce a deterministic generation by using the same seed.
 */
extern void GenerateSquare(double x_pos[], double y_pos[], int nb, unsigned int seed);

/**
 * This function generates random points.
 *
 * This function will store Cartesian random coordinate points in the two arrays x_pos and y_pos.
 * Points are first chosen in polar coordinates, with a uniform distribution on the angle,
 * and a decreasing exponential distribution on the distance from the center, then converted to
 * Cartesian coordinates.
 *
 * @param x_pos the array to store the X-coordinates of the points
 * @param y_pos the array to store the Y-coordinates of the points
 * @param nb the number of points to store in the arrays.
 * Caution: this number must not be larger than the size of the arrays.
 * @param seed a number identifying each random generation.
 * You will reproduce a deterministic generation by using the same seed.
 */
extern void GenerateGalaxy(double x_pos[], double y_pos[], int nb, unsigned int seed);

/**
 * This function plots a set of points and draws a polygon.
 *
 * This function helps animating the Convex Hull construction,
 * you might call it everytime you have a new potential point in the Convex Hull.
 * The full set of points are first plotted, and then a polygon of the first points is drawn on top
 *
 * @param x_pos,y_pos the full set of coordinate points
 * @param nb_total_points the total number of points.
 * Caution: the number of elements in the two coordinate arrays must be large enough so that accessing this number of
 * points will not exceed the arrays' size.
 * @param nb_hull_points the number of points of the candidate Convex Hull.
 * Caution: this number of points should be less or equal to the total number of points.
 * The first points in the arrays will be used to draw a closed polygon.
 */
extern void DrawConvexHull(double x_pos[], double y_pos[], int nb_total_points, int nb_hull_points);

/**
 * This function clears the window.
 */
extern void EmptySpace(void);
